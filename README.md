

## 系统接口设计

---

#### 1. 注册

```
createAccount:
	request: (userId, passwordSHA256)
	response: (accessToken, refreshToken)
	error: userIdExist/passwordInvalid
```

> 注册后自动返回登录态，后续可以直接拉取业务数据。

#### 2. 登录

```
Login:
	request: (userId, passwordSHA256)
	response: (accessToken, refreshToken)
	error: wrongUserId/wrongPassword
```

> 登录采用轻量级设计：
>
> accessToken：登录相当于建立了个会话，accessToken是server生成的一个hash，server以此为Key保存了这个会话相关的信息，如：userId；同时作为client的登录态，后续的业务接口每次都要传输这个accessToken。
>
> 过期控制：accessToken的过期时间短，大约两小时，在临近过期前30分钟内，server自动下发一对新的accessToken和refreshToken，放在业务请求的回包的头部，下次client必须使用新的accessToken来发业务包。如果accessToken过期了，可以使用refreshToken来Relogin，refreshToken的过期长，大约一个月，但refreshToken只能用一次，Relogin时会自动下发新的refreshToken。
>
> 互踢：当新的client登录之后，旧client的accessToken和refreshToken都会失效。

#### 3. 业务数据

```
Business:
	request: (accessToken, params)
	response: bussinessData
	error: accessTokenExpired
```

> 业务接口的输入输出都包在一个VipUserResquest/VipUserResponse的大数据结构里面。其中VipUserResquest有一个必填字段sessionId。

#### 4.重登

```
Relogin:
	request: (refreshToken)
	response: new-accessToken， new-refreshToken
	error: refreshTokenExpired
```

> 重登可以在refreshToken未过期前的任意时刻进行，重登后，旧的accessToken和refreshToken都会失效。

#### 5. 登出

```
Logout:
	request: (accessToken)
	response: <empty>
	error: reopenKeyExpired
```

> 登出之后，accessToken和refreshToken都会失效



### server端角色分类

设计一个接入机，负责注册、登录、票据刷新、用户合入法验证。解析业务数据的外层大包VipUserResquest/VipUserResponse，将内部的输入和输出参数转交给业务机处理。

业务机负责处理具体业务处理，不用关心用户合法验证等其它外围逻辑。

账户机是一个特殊的业务机，接管接入机的认证职责，负责用户管理，包含创建用户和验证用户，同时保存用户的敏感数据，比如密码hash、手机、邮箱、别名、第三方openid/appid，这些都可以做为用户的登录的唯一key。

## 数据存储结构

### 票据设计

接入机采用redis保存用户的登录态，提高转发效率。

票据数据：

| key         | uuid     | timestamp(ms) | refreshToken |
| :---------- | -------- | ------------- | ------------ |
| accessToken | <string> | <UInt64>      | <string>     |

> refreshToken：encrypt_aes_cbc(uuid, timestamp, random32)，可以逆向解密
>
> accessToken： sha256(refreshToken)，相当于session的唯一标识。

已登录状态：

| uuid | accessToken-Set（后期可能允许多端登录） |
| ---- | --------------------------------------- |
|      |                                         |



账户数据：

| uuid     | userId   | passwordSHA256 |
| -------- | :------- | :------------- |
| <string> | <string> | <string>       |

> 账户数据在初期系统接入量少且业务简单的情形下，先直接保存在接入机。后续业务复杂后，支持多种登录方式，有手机/邮箱/别名等更多字段时，再使用关系型数据库保存。







