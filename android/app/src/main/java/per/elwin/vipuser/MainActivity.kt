package per.elwin.vipuser

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.text.InputType
import android.text.method.PasswordTransformationMethod
import android.util.Log
import kotlinx.android.synthetic.main.activity_main.*
import org.jetbrains.anko.*
import org.jetbrains.anko.sdk25.coroutines.onClick

class MainActivity : AppCompatActivity() {


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
//        setContentView(R.layout.activity_main)
//        sample_text.text = stringFromJNI()

        verticalLayout {
            padding = 16
            val userName = editText {
                hint = "enter you user name"
            }
            val password = editText() {
                hint = "enter you password"
                transformationMethod = PasswordTransformationMethod.getInstance()
                //inputType = InputType.TYPE_TEXT_VARIATION_PASSWORD
            }
            button {
                text = "Login"
                onClick {
                    perform(false, userName.text.toString(), password.text.toString())
                }
            }
            button {
                text = "Register"
                onClick {
                    perform(true, userName.text.toString(), password.text.toString())
                }
            }
        }
    }



    private fun perform(isRegister: Boolean, userName: String?, password: String?) {
        if (userName == null || password == null) {
            Log.e(LOG_TAG, "name and password can't be empty");
            return
        }
        if (userName.isEmpty() || password.isEmpty()) {
            Log.e(LOG_TAG, "name and password can't be empty");
            return
        }


    }


    private fun handleAccountResponse(isRegister: Boolean) {

    }


    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {
        val LOG_TAG = "VipUser"
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("native-lib")
        }
    }

}

