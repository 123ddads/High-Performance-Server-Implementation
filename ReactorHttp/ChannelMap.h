#pragma once
#include <stdbool.h>

struct ChannelMap {
	int size;	// 记录指针指向的数组的元素总个数
	struct Channel** list;	// 指向struct Channel* list[] 类型数组
};

// 初始化
struct ChannelMap* ChannelMapInit(int size);

// 清空map
void ChannelMapClear(struct ChannelMap* map);

// 为map重新分配内存空间
bool MakeMapRoom(struct ChannelMap* map, int newSize, int unitSize);