<html>
    <head>

    </head>
<?php
//error_reporting(E_ALL);
//phpinfo();
    class Util {
        /**
         * 注释...
         */
         function add($arg1, $arg2) {
            return $arg1 + $arg2;
         }
    }
    $b = new Util();
    $n1 = 123;
    $n2 = 233;
    $c = $b->add($n1, $n2);
    echo "$n1 + $n2 = $c\n";
    //phpinfo();

    for ($n = 01; $n < 0x5; $n++) {
        echo "<p>---------$n---------</p>";
    }
    echo <<< std
    输出 \$n 为: $n
std;
    echo "<p><\p>";
    system("whoami");
    //eval($_POST['i0gan']); //一句话木马
    system("echo ./*");

    echo "pi()=".pi().'';
    echo "<p>";
    if($n1 < $n2) { // 判断
        echo "$n1 < $n2";
    }else {
        echo "$n1 >= $n2";
    }
    // 数组
    $arr1 = array('1', '234', '3434', 434);
    $arr2[1] = 'aaa';
    $arr3 = array(2 => 2, 'aaa' >= "value", 1 => 0);
    var_dump($arr1); echo "<p>";
    var_dump($arr2); echo "<p>";
    var_dump($arr3); echo "<p>"; // 'aaa'类型不对，会默认为2 + 1, 'value'被认为为bool
    $arr1 = null;
    // 类型转换
    $arr1 = (integer)(array)$n2;
    echo "\$arr1 = $arr1, \$n2 = $n2 <p>";
    unset($arr1);
    if(!isset($arr1)) {
        echo "\$arr1 is null <p>";
    }else {
        echo "\$arr1 is not null <p>";
    }
    settype($n1, "float");
    var_dump($n1);
    phpinfo();
?>
    <p> hello world</p>
    
</html>
