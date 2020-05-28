# ImageView

Button的其他衍生控件: ToggleButton, Switch

常用属性

加载网络图片

```xml
<ImageView
        android:layout_width="300dp"
        android:layout_height="200dp"
        android:background="#AA00FF"
        android:src="@drawable/lock" <!--图片-->
        android:scaleType="fitXY"/>  <!--拉伸xy-->
```





### 用第三方库加载网络图片:

https://github.com/bumptech/glide

通过jar包导入lib或者通过grade来导入依赖

```
repositories {
  mavenCentral()
  google()
}

dependencies {
  implementation 'com.github.bumptech.glide:glide:4.11.0'
  annotationProcessor 'com.github.bumptech.glide:compiler:4.11.0'
}
```

导入到build.gradle中即可使用该库

#### 使用

```java
// For a simple view:
@Override public void onCreate(Bundle savedInstanceState) {
  ...
  ImageView imageView = (ImageView) findViewById(R.id.my_image_view);

  Glide.with(this).load("http://goo.gl/gEgYUd").into(imageView);
}

// For a simple image list:
@Override public View getView(int position, View recycled, ViewGroup container) {
  final ImageView myImageView;
  if (recycled == null) {
    myImageView = (ImageView) inflater.inflate(R.layout.my_image_view, container, false);
  } else {
    myImageView = (ImageView) recycled;
  }

  String url = myUrls.get(position);

  Glide
    .with(myFragment)
    .load(url)
    .centerCrop()
    .placeholder(R.drawable.loading_spinner)
    .into(myImageView);

  return myImageView;
}
```



加载需要要网络请求权限, 在 AndroidManifest.xml中添加

```xml
 <uses-permission android:name="android.permission.INTERNET"/>
```

