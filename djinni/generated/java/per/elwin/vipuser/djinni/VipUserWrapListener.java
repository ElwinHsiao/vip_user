// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vipuser.djinni

package per.elwin.vipuser.djinni;

public abstract class VipUserWrapListener {
    public abstract void onCreateAccount(ReplyResult result, TokenInfo token);

    public abstract void onLogin(ReplyResult result, TokenInfo token);

    public abstract void onReLogin(ReplyResult result, TokenInfo token);

    public abstract void onLogout(ReplyResult result);

    public abstract void onDoBusiness(ReplyResult result, byte[] response);
}
