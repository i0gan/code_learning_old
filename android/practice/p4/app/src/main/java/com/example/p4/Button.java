package com.example.p4;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class Button extends AppCompatActivity {
    private android.widget.Button btn2;
    private android.widget.TextView tv1;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_button);

        android.widget.Button btn2 = (android.widget.Button) findViewById(R.id.button_2);
        btn2.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                //调用Toast
                Toast.makeText(Button.this, "button 2被点击", Toast.LENGTH_SHORT).show();
            }
        });

        tv1 = (TextView) findViewById(R.id.text_view_1);
        tv1.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                Toast.makeText(Button.this, "textView 被点击了", Toast.LENGTH_SHORT).show();
            }
        });
    }

    //通过xml中实现调用的, 注意, 参数必须有View
    public void showToast(View view) {
        Toast.makeText(this,"你点击了 button 5", Toast.LENGTH_SHORT).show(); //弹出信息
    }
}