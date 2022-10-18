package com.blink.blinkapp

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.ToggleButton
import kotlinx.coroutines.GlobalScope
import kotlinx.coroutines.async
import kotlinx.coroutines.launch
import vendor.blink.ledmanager.LedManager

class MainActivity : AppCompatActivity() {

    private lateinit var ledManager: LedManager
    private var buttonIsChecked : Boolean = false;

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        ledManager = LedManager.getInstance();
        val toggle: ToggleButton = findViewById(R.id.toggleButton);

        toggle.setOnCheckedChangeListener { _, isChecked ->
            buttonIsChecked = isChecked
        }

        GlobalScope.launch {
            blink()
        }
    }

    suspend fun blink() = GlobalScope.async {
        while (true) {
            while (buttonIsChecked) {
                ledManager.ledON()
                Thread.sleep(1000)
                ledManager.ledOFF()
                Thread.sleep(1000)
            }
        }
    }
}