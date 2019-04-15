package me.jameshunt.nativejni

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        var last: String? = "wow"
        var keyValueStore = newKeyStoreValue()

        this.button.setOnClickListener {
            sample_text.text = last?.let { keyValueStore.get(it)?: "wow" }.also {
                last = it

                if(last == "wow") {
                    keyValueStore.close()
                    keyValueStore = newKeyStoreValue()
                }
            }
        }
    }

    private fun newKeyStoreValue() = KeyValueStore().apply {
        put("wow", "woow")
        put("woow", "bob")
        put("bob", "sup")
        put("sup", "wow")
    }
}
