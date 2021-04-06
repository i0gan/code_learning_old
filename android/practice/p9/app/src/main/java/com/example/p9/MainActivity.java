package com.example.p9;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.ListView;
import android.widget.Toast;

/* ListView
 * Adapter 接口
 *
*/
public class MainActivity extends AppCompatActivity {
    private ListView list_view_1;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        list_view_1 = (ListView) findViewById(R.id.list_view_1);

    }
}