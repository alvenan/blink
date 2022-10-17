package com.blink.blinkapp

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.ToggleButton
import vendor.blink.ledmanager.LedManager

class MainActivity : AppCompatActivity() {

    val ledManager: LedManager = LedManager.getInstance()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val toggle: ToggleButton = findViewById(R.id.toggleButton)
        toggle.setOnCheckedChangeListener { _, isChecked ->
                if (isChecked)
                    ledManager.ledON()
                else
                    ledManager.ledOFF()
        }
    }
}