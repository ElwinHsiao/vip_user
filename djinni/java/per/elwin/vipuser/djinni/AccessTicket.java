// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vipuser.djinni

package per.elwin.vipuser.djinni;

import javax.annotation.CheckForNull;
import javax.annotation.Nonnull;

/*package*/ final class AccessTicket {


    /*package*/ final String mUuid;

    /*package*/ final String mAccessToken;

    public AccessTicket(
            @Nonnull String uuid,
            @Nonnull String accessToken) {
        this.mUuid = uuid;
        this.mAccessToken = accessToken;
    }

    @Nonnull
    public String getUuid() {
        return mUuid;
    }

    @Nonnull
    public String getAccessToken() {
        return mAccessToken;
    }

    @Override
    public String toString() {
        return "AccessTicket{" +
                "mUuid=" + mUuid +
                "," + "mAccessToken=" + mAccessToken +
        "}";
    }

}
