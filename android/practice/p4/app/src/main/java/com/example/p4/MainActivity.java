package com.example.p4;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {
    private Button btn;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        btn = (Button) findViewById(R.id.button_1);
        btn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                //切换页面
                Intent intent = new Intent(MainActivity.this, com.example.p4.Button.class);
                startActivity(intent);
            }
        });

    }
}
