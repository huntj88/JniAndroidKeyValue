package me.jameshunt.nativejni

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val keyValueStore = KeyValueStore().apply {
            put("wow","woow")
            put("woow", "bob")
            put("bob", "sup")
            put("sup", "wow")
        }

        var last = "wow"

        this.button.setOnClickListener {
            sample_text.text = keyValueStore.get(last).also {
                last = it

                if(last == "wow") {
                    keyValueStore.close()
                }
            }
        }
    }
}
