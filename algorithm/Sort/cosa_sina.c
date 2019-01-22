//
//  cosa_sina.c
//  algorithm
//
//  Created by wangbinbin on 2019/1/22.
//  Copyright © 2019 wangbinbin. All rights reserved.
//

#include "cosa_sina.h"

//如何编程实现“求一个数的平方根”？要求精确到小数点后 6 位...
void cosa_sina(int value)
{
    // 要求 平方根的值
    double x = value;
    // 我想要的答案
    double y = 0;
    // 二分查找 的最小值
    double min = 0;
    // 二分查找的最大值
    double max = x;
    // 当 x 小于 0 的情况
    if(x > 0 && x < 1){
        // 当 x 等于 1 的情况
    }else if(x==1){
        y = 1;
    }else if (x > 1){
        while(min <= max){
            double middle = min + (max - min) / 2.0;
            printf("\tmiddle = %lf\n",middle);
            // 我们的精度是 小数点 后 6位， 所以要借助 0.000001
            double temp1 = (middle + 0.000001) * (middle + 0.000001);
            double temp2 = (middle - 0.000001) * (middle - 0.000001);
            // 得到正确答案的条件
            if (temp1 > x && temp2 < x){
                y = middle;
                break;
            }
            double temp3 = middle * middle;
            // 逐步趋近 得到正确的值
            if (temp3 > x){
                max = middle;
            }else if (temp3 < x){
                min = middle;
            }
        }
    }
    printf("\n\ty = %lf\n",y);
}


// 使用递归重新实现
void cosa_sina_01(int value, double min, double max){
    // 要求 平方根的值
    double x = value;
    // 我想要的答案
    double y = 0;
//    // 二分查找 的最小值
//    double min = min;
//    // 二分查找的最大值
//    double max = max;
    // 当 x 小于 0 的情况
    if(x > 0 && x < 1){
        // 当 x 等于 1 的情况
    }else if(x==1){
        y = 1;
    }else if (x > 1){
        double middle = min + (max - min) / 2.0;
        printf("\tmiddle = %lf\n",middle);
        // 我们的精度是 小数点 后 6位， 所以要借助 0.000001
        double temp1 = (middle + 0.000001) * (middle + 0.000001);
        double temp2 = (middle - 0.000001) * (middle - 0.000001);
        // 得到正确答案的条件
        if (temp1 > x && temp2 < x){
            y = middle;
            printf("\n\ty = %lf\n",y);
            return ;
        }
        double temp3 = middle * middle;
        // 逐步趋近 得到正确的值
        if (temp3 > x){
            max = middle;
        }else if (temp3 < x){
            min = middle;
        }
        // 重复调用该方法
        cosa_sina_01(value,min,max);
    }
//    printf("\n\ty = %lf\n",y);
}

void cosa_sina_test(void)
{
//    cosa_sina(5);
    cosa_sina_01(5,0,5);
}
