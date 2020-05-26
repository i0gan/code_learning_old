# CheckBox

*  样式
* 监听事件





### java代码

```java
package com.example.p7;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.Toast;

/*
* CheckBox
* */

public class MainActivity extends AppCompatActivity {
    private CheckBox check_box_1;
    private CheckBox check_box_2;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        check_box_1 = (CheckBox) findViewById(R.id.check_box_1);
        check_box_2 = (CheckBox) findViewById(R.id.check_box_2);
        check_box_1.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                Toast.makeText(MainActivity.this, isChecked? "1选中":"1未选中", Toast.LENGTH_SHORT).show();
            }
        });
        check_box_2.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                Toast.makeText(MainActivity.this, isChecked? "2选中": "2未选中", Toast.LENGTH_SHORT).show();
            }
        });
    }
}
```

