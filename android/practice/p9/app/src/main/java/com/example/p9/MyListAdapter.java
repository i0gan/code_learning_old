package com.example.p9;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

//适配器
public class MyListAdapter extends BaseAdapter {
    private Context context_;
    private LayoutInflater layoutInflater_;
    public MyListAdapter(Context context) {
        context_ = context;
        layoutInflater_ = LayoutInflater.from(context);
    }

    static class ViewHolder {
        public ImageView image_view;
        public TextView text_view_title, text_view_time, text_view_content;
    }

    @Override
    public int getCount() {
        return 0;
    }

    @Override
    public Object getItem(int position) {
        return null;
    }

    @Override
    public long getItemId(int position) {
        return 0;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        if(convertView == null) {
            //convertView = layoutInflater_.inflate(R.layout_list_item, null);

        }
        return null;
    }
}
