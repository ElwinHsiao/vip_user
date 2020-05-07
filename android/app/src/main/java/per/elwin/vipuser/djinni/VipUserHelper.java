package per.elwin.vipuser.djinni;

import android.os.Handler;
import android.util.Log;

import androidx.annotation.NonNull;

import javax.annotation.Nonnull;

import per.elwin.vipuser.Utils;

public class VipUserHelper extends VipUserWrapListener {

    public static class VipUserResult {
        private int code;
        private String message;

        public VipUserResult(int code, String message) {
            this.code = code;
            this.message = message;
        }

        public int getCode() {
            return code;
        }

        public String getMessage() {
            return message;
        }

        @NonNull
        @Override
        public String toString() {
            return "VipUserResult{code=" + code + ", message=" + message + "}";
        }
    }

    public interface OnVipUserListener {
        void onCreateAccountResult(VipUserResult result);
        void onLoginResult(VipUserResult result);
        void onReLoginResult(VipUserResult result);
        void onLogoutResult(VipUserResult result);
        void onDoBusinessResult(VipUserResult result, byte[] response);
    }

    public void setOnVipUserListener(OnVipUserListener listener) {
        this.listener = listener;
    }

    public void init(String serverAddr, String publicKey) {
        vipUserClientWrap = VipUserClientWrap.createWithListener(this);
        vipUserClientWrap.init(serverAddr, publicKey);
    }

    private VipUserClientWrap vipUserClientWrap;
    private OnVipUserListener listener;
    private TokenInfo tokenInfo;

    public void register(String userName, String password) {
        AccountInfo accountInfo = new AccountInfo(userName, password);
        vipUserClientWrap.createAccount(accountInfo);
    }

    public void login(String userName, String password) {
        AccountInfo accountInfo = new AccountInfo(userName, password);
        vipUserClientWrap.login(accountInfo);
    }

    public void doBusiness(byte[] request) {
        AccessTicket ticket = getTicket();
        if (ticket == null) {
            Log.e(Utils.LOG_TAG, "can't do business because have't login");
            if (listener != null) listener.onDoBusinessResult(new VipUserResult(-1, "have't login"), null);
            return;
        }
        vipUserClientWrap.doBusiness(getTicket(), request);
    }

    public void reLogin() {
        AccessTicket ticket = getTicket();
        if (ticket == null) {
            Log.e(Utils.LOG_TAG, "can't re-login because have't login");
            if (listener != null) listener.onDoBusinessResult(new VipUserResult(-1, "have't login"), null);
            return;
        }
        vipUserClientWrap.reLogin(getTicket());
    }

    public void logout() {
        AccessTicket ticket = getTicket();
        if (ticket == null) {
            Log.e(Utils.LOG_TAG, "do not need logout because have't login");
            if (listener != null) listener.onDoBusinessResult(new VipUserResult(0, "have't login"), null);
            return;
        }

        vipUserClientWrap.logout(getTicket());
    }

    private boolean isLogin() {
        return tokenInfo != null;
    }

    private AccessTicket getTicket() {
        if (tokenInfo == null) return null;
        return new AccessTicket(tokenInfo.getUuid(), tokenInfo.getAccessToken());
    }



    @Override
    public void onCreateAccount(@Nonnull ReplyResult result, @Nonnull TokenInfo token) {
        VipUserResult vipUserResult = new VipUserResult(result.mCode, result.mMessage);
        Log.e(Utils.LOG_TAG, "onCreateAccount: result=" + vipUserResult);

        if (result.mCode == 0) {
            this.tokenInfo = token;
        }

        if (listener != null) listener.onCreateAccountResult(vipUserResult);

    }

    @Override
    public void onLogin(@Nonnull ReplyResult result, @Nonnull TokenInfo token) {
        VipUserResult vipUserResult = new VipUserResult(result.mCode, result.mMessage);
        Log.e(Utils.LOG_TAG, "onLogin: result=" + vipUserResult);
        if (result.mCode == 0) {
            this.tokenInfo = token;
        }
        if (listener != null) listener.onLoginResult(vipUserResult);
    }

    @Override
    public void onReLogin(@Nonnull ReplyResult result, @Nonnull TokenInfo token) {
        VipUserResult vipUserResult = new VipUserResult(result.mCode, result.mMessage);
        Log.e(Utils.LOG_TAG, "onReLogin: result=" + vipUserResult);
        if (result.mCode == 0) {
            this.tokenInfo = token;
        }
        if (listener != null) listener.onReLoginResult(vipUserResult);
    }

    @Override
    public void onLogout(@Nonnull ReplyResult result) {
        VipUserResult vipUserResult = new VipUserResult(result.mCode, result.mMessage);
        Log.e(Utils.LOG_TAG, "onLogout: result=" + vipUserResult);
        if (result.mCode == 0) {
            this.tokenInfo = null;
        }
        if (listener != null) listener.onLogoutResult(vipUserResult);
    }

    @Override
    public void onDoBusiness(@Nonnull ReplyResult result, @Nonnull byte[] response) {
        VipUserResult vipUserResult = new VipUserResult(result.mCode, result.mMessage);
        Log.e(Utils.LOG_TAG, "onDoBusiness: result=" + vipUserResult);

        if (listener != null) listener.onDoBusinessResult(vipUserResult, response);
    }
}
