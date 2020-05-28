package com.example.p8;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.ImageView;

import com.bumptech.glide.Glide; //导入第三方库

public class MainActivity extends AppCompatActivity {
    private ImageView image_view;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        image_view =(ImageView) findViewById(R.id.image_view_4);
        //加载网路图片需要网络请求权限
        Glide.with(this).load("https://ss3.bdstatic.com/70cFv8Sh_Q1YnxGkpoWK1HF6hhy/it/u=25753986,2356062801&fm=26&gp=0.jpg") //加载网络图片
                .into(image_view);

    }
}
