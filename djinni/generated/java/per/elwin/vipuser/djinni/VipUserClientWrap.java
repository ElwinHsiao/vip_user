// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vipuser.djinni

package per.elwin.vipuser.djinni;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class VipUserClientWrap {
    /** Instance Method  */
    public abstract void init(String svraddr, String pubkey);

    public abstract void createAccount(AccountInfo account);

    public abstract void login(AccountInfo account);

    public abstract void reLogin(AccessTicket ticket);

    public abstract void logout(AccessTicket ticket);

    public abstract void doBusiness(AccessTicket ticket, byte[] request);

    /** Class Method */
    public static VipUserClientWrap createWithListener(VipUserWrapListener listener)
    {
        return CppProxy.createWithListener(listener);
    }

    private static final class CppProxy extends VipUserClientWrap
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void _djinni_private_destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            _djinni_private_destroy();
            super.finalize();
        }

        @Override
        public void init(String svraddr, String pubkey)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_init(this.nativeRef, svraddr, pubkey);
        }
        private native void native_init(long _nativeRef, String svraddr, String pubkey);

        @Override
        public void createAccount(AccountInfo account)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_createAccount(this.nativeRef, account);
        }
        private native void native_createAccount(long _nativeRef, AccountInfo account);

        @Override
        public void login(AccountInfo account)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_login(this.nativeRef, account);
        }
        private native void native_login(long _nativeRef, AccountInfo account);

        @Override
        public void reLogin(AccessTicket ticket)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_reLogin(this.nativeRef, ticket);
        }
        private native void native_reLogin(long _nativeRef, AccessTicket ticket);

        @Override
        public void logout(AccessTicket ticket)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_logout(this.nativeRef, ticket);
        }
        private native void native_logout(long _nativeRef, AccessTicket ticket);

        @Override
        public void doBusiness(AccessTicket ticket, byte[] request)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            native_doBusiness(this.nativeRef, ticket, request);
        }
        private native void native_doBusiness(long _nativeRef, AccessTicket ticket, byte[] request);

        public static native VipUserClientWrap createWithListener(VipUserWrapListener listener);
    }
}
