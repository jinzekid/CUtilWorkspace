//
//  SocketClient.c
//  CTestProject
//
//  Created by JasonLu on 16/10/13.
//  Copyright © 2016年 JasonLu. All rights reserved.
//

#include "SocketClient.h"
#include <stdlib.h>

int cltSocketRev2_Free(unsigned char **buf /*in*/) {
  if (buf == NULL)
    return -1;
  if (*buf != NULL) {
    free(*buf);
  }
  *buf = NULL;
  return 0;
}
