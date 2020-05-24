package com.example.p3;

import androidx.appcompat.app.AppCompatActivity;
import android.graphics.Paint;
import android.os.Bundle;
import android.text.Html;
import android.widget.TextView;

public class TextViewActivity extends AppCompatActivity {
    private TextView tv1, tv3, tv4;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_text_view);
        tv1 = (TextView) findViewById(R.id.text_view_1);
        tv1.getPaint().setFlags(Paint.STRIKE_THRU_TEXT_FLAG); //添加中划线
        tv1.getPaint().setAntiAlias(true); //去除锯齿

        tv3 = (TextView) findViewById(R.id.text_view_3);
        tv3.getPaint().setFlags(Paint.UNDERLINE_TEXT_FLAG);  //添加下划线
        tv3.getPaint().setAntiAlias(true);

        tv4 = (TextView) findViewById(R.id.text_view_4);
        tv4.setText(Html.fromHtml("<u>Hello</u>")); //使用html方式显示

    }
}
