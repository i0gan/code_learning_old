package com.example.p1;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity { //继承自AppCompatActivity
    protected void onCreate(Bundle savedInstanceState) { //创建的时候调用
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main_activity); //设置主页面为main_activity, 需要在mainifests文件中进行设置

    }
}
