//
//  other_配置文件读写.h
//  CTestProject
//
//  Created by JasonLu on 2017/6/29.
//  Copyright © 2017年 JasonLu. All rights reserved.
//

#ifndef other________h
#define other________h

#include <stdio.h>

int getCfgItem(char* pin_fileName, char* pin_key, char* pout_value, int* pout_valueLen);

int setCfgItem(char* pin_fileName, char* pin_itemName, char* pint_itemValue, int itemValueLen);


#endif /* other________h */
