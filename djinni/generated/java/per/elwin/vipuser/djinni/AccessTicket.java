// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from vipuser.djinni

package per.elwin.vipuser.djinni;

public final class AccessTicket {


    /*package*/ final String mUuid;

    /*package*/ final String mAccessToken;

    public AccessTicket(
            String uuid,
            String accessToken) {
        this.mUuid = uuid;
        this.mAccessToken = accessToken;
    }

    public String getUuid() {
        return mUuid;
    }

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