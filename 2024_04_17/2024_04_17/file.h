#pragma once

#include"SList.h"
#include"_Time.h"

//用文件保存运行的信息
void saveContext(SLNode* pcur);
//获取文件保存的信息
void getContext(SLNode** pcur);