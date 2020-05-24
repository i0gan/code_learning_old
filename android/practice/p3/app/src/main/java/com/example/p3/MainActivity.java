package com.example.p3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    private Button mBtn; //声明一个button按钮
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mBtn = (Button)findViewById(R.id.btn_1); //根据id找botton

        //使用重写内部类实现事件的监听调用
        mBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //点击事件调用此函数
                Intent intent = new Intent(MainActivity.this, TextViewActivity.class);
                startActivity(intent);

            }
        });

    }
}
