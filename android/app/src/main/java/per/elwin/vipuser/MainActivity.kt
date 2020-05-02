package per.elwin.vipuser

import android.graphics.Color
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.text.method.PasswordTransformationMethod
import android.util.Log
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.fragment.app.Fragment
import org.jetbrains.anko.*
import org.jetbrains.anko.sdk25.coroutines.onClick
import org.jetbrains.anko.support.v4.UI
import per.elwin.vipuser.djinni.VipUserHelper
import kotlin.reflect.KClass

class MainActivity : AppCompatActivity(), VipUserPresenter, VipUserHelper.OnVipUserListener {

    private val mainFragment = object : Fragment() {
        override fun onCreateView(
            inflater: LayoutInflater,
            container: ViewGroup?,
            savedInstanceState: Bundle?
        ): View? {
            return UI {
                verticalLayout {
                    padding = 16

                    button {
                        text = "Test Register"
                        onClick {
                            switchFragment(RegisterFragment::class)
                        }
                    }
                    button {
                        text = "Test Login"
                        onClick {

                        }
                    }
                    button {
                        text = "Test Do Business"
                        onClick {

                        }
                    }
                    button {
                        text = "Test ReLogin"
                        onClick {

                        }
                    }
                    button {
                        text = "Test Logout"
                        onClick {

                        }
                    }
                }
            }.view
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
//        setContentView(R.layout.activity_main)
//        sample_text.text = stringFromJNI()

        verticalLayout {
            padding = 16
            button {
                text = "Back"
                onClick {
                    supportFragmentManager.popBackStack()
                }
            }
            frameLayout {
                id = R.id.fragment_container
            }
        }

        supportFragmentManager.beginTransaction()
            .add(R.id.fragment_container, mainFragment)
            .commit()
    }

    private var currentFragment: VipUserFragment? = null
    private fun<F: VipUserFragment> switchFragment(fragmentClass: KClass<F>) {
        val fragment =  fragmentClass.constructors.first().call(this)
        supportFragmentManager.beginTransaction()
            .replace(R.id.fragment_container, fragment)
            .addToBackStack(null)
            .commit()
        currentFragment = fragment
    }

    private fun performAccount(isRegister: Boolean, userName: String?, password: String?) {
        if (userName == null || password == null) {
            Log.e(Utils.LOG_TAG, "name and password can't be empty");
            return
        }
        if (userName.isEmpty() || password.isEmpty()) {
            Log.e(Utils.LOG_TAG, "name and password can't be empty");
            return
        }

        if (isRegister) {
            vipUserHelper.register(userName, password)
        } else {
            vipUserHelper.login(userName, password)
        }
    }


    private val vipUserHelper = VipUserHelper().apply {
        setOnVipUserListener(this@MainActivity)
    }
    override fun register(userName: String?, password: String?) {
        performAccount(true, userName, password)
    }

    override fun login(userName: String?, password: String?) {
        performAccount(false, userName, password)
    }

    override fun logout() {
        vipUserHelper.logout()
    }

    override fun reLogin() {
        vipUserHelper.reLogin()
    }

    override fun doBusiness(bytes: ByteArray) {
        vipUserHelper.doBusiness(bytes)
    }

    // ---- VipUserListener ----
    override fun onCreateAccountResult(result: VipUserHelper.VipUserResult?) {
        TODO("Not yet implemented")
    }

    override fun onReLoginResult(result: VipUserHelper.VipUserResult?) {
        TODO("Not yet implemented")
    }

    override fun onLogoutResult(result: VipUserHelper.VipUserResult?) {
        TODO("Not yet implemented")
    }

    override fun onDoBusinessResult(result: VipUserHelper.VipUserResult?, response: ByteArray?) {
        TODO("Not yet implemented")
    }

    override fun onLoginResult(result: VipUserHelper.VipUserResult?) {
        TODO("Not yet implemented")
    }


    companion object {
        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("vipuser")
        }
    }

}

interface VipUserPresenter {
    fun register(userName: String?, password: String?)
    fun login(userName: String?, password: String?)
    fun logout()
    fun reLogin()
    fun doBusiness(bytes: ByteArray)
}

abstract class VipUserFragment(val presenter: VipUserPresenter): Fragment() {
    fun updateState(isSuccess: Boolean, message: String) {
        if (!isDetached) {
            onUpdateState(isSuccess, message)
        }
    }
    abstract fun onUpdateState(isSuccess: Boolean, message: String)
}

class RegisterFragment(presenter: VipUserPresenter): VipUserFragment(presenter) {

    lateinit var statusView: TextView

    override fun onCreateView(
        inflater: LayoutInflater,
        container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        return UI {
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
                        presenter.register(userName.text.toString(), password.text.toString())
                    }
                }

                statusView = textView {
                    backgroundColor = Color.BLACK
                    textColor = Color.WHITE
                }.lparams {
                    width = matchParent
                    height = 80
                }
            }
        }.view
    }

    override fun onUpdateState(isSuccess: Boolean, message: String) {
        statusView.textColor = if(isSuccess) Color.RED else Color.GREEN;
        statusView.text = message
    }

}
