package com.example.p6;

import androidx.annotation.IdRes;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    /**
     * RadioButton练习
     */
    private Button button_test;
    private RadioButton radio_button;
    private RadioGroup radio_group_1;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        button_test = (Button) findViewById(R.id.button_test);
        setOnClickListeners();

        //设置RadioGroup监听事件
        radio_group_1 = (RadioGroup) findViewById(R.id.radio_group_1);
        radio_group_1.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                RadioButton radioButton = (RadioButton) group.findViewById(checkedId);
                Toast.makeText(MainActivity.this, radioButton.getText(), Toast.LENGTH_SHORT).show();
            }
        });

    }

    //采用另一种方式实现onClick事件的管理
    private void setOnClickListeners() { //设置监听事件
        OnClick onClick = new OnClick();
        button_test.setOnClickListener(onClick);
    }

    //onclick事件调用
    private class OnClick implements View.OnClickListener {
        @Override
        public void onClick(View v) {
            switch(v.getId()) {
                case R.id.button_test: {
                    Toast.makeText(MainActivity.this, "点击了testButton", Toast.LENGTH_SHORT).show();
                } break;
                default: {
                    break;
                }
            }
        }
    }
}
