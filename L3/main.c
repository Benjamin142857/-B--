#include <stdio.h>
#include "SeqQueue.h"


//获取农民的位置
int get_farmer_location(int currentLocation) {
    return ((currentLocation&16) == 16);
}


//获取狮子的位置
int get_lion_location(int currentLocation) {
    return ((currentLocation&8) == 8);
}


//获取狼的位置
int get_wolf_location(int currentLocation) {
    return ((currentLocation&4) == 4);
}


//获取羊的位置
int get_goat_location(int currentLocation) {
    return ((currentLocation&2) == 2);
}


//获取白菜的位置
int get_cabbage_location(int currentLocation) {
    return ((currentLocation&1) == 1);
}


// 判断当前状态是否安全
int is_safe(int currentLocation) {
    int far = get_farmer_location(currentLocation);
    int lio = get_lion_location(currentLocation);
    int wol = get_wolf_location(currentLocation);
    int goa = get_goat_location(currentLocation);
    int cab = get_cabbage_location(currentLocation);

    // 当农夫不在一侧时，狮！=狼，狼！=羊，羊！=菜
    if((far != lio) && (lio == wol)) {
        return 0;
    }
    else if((far != wol) && (wol == goa)) {
        return 0;
    }
    else if((far != goa) && (goa == cab)) {
        return 0;
    }
    else {
        return 1;
    }
}


// 执行农夫过河
void cross_river() {
    int i, movers, location, newlocation;
    int cabb=2;  // 两次能与白菜一起运的机会
    int route[32]; //用于记录已考虑的状态路径
    PSeqQueue moveTo; //用于记录可以安全到达的中间状态

    moveTo = SeqQueue_create(40); //创建空队列
    SeqQueue_enq(moveTo, 0x00); //初始状态进队列

    for (i = 0; i < 32; i++)
        route[i] =  -1;

    //准备数组route初值
    route[0] = 0;

    while (!SeqQueue_IsEmpty(moveTo) && (route[31] ==  - 1))
    {
        location = SeqQueue_GetFirst(moveTo); //取队头状态为当前状态
        SeqQueue_deq(moveTo);

        //考虑各种物品移动
        for (movers = 1; movers <= 16; movers <<= 1)
            //农夫与移动的物品在同一侧
            if ((0 != (location & 0x16)) == (0 != (location & movers)))
            {
                newlocation = location ^ (0x16 | movers); //计算新状态

                //新状态安全且未处理
                if (is_safe(newlocation) && (route[newlocation] ==  -1))
                {
                    route[newlocation] = location; //记录新状态的前驱
                    SeqQueue_enq(moveTo, newlocation); //新状态入队
                }
            }
    }

}

int main() {


    return 0;
}