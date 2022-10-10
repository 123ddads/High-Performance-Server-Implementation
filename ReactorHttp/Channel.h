#pragma once
#include <stdbool.h>

// 定义文件的读写事件
enum FdEvent {
	TimeOut = 0x01,
	ReadEvect = 0x02,
	WriteEvent = 0x04
};

// 定义函数指针
typedef int(*handleFunc)(void* arg);

struct Channel {
	int fd;			// 文件描述符
	int events;		// 事件
	handleFunc readCallback;	// 读回调函数
	handleFunc writeCallBack;	// 写回调函数
	void* arg;		// 回调函数的参数
};

// 初始化一个Channel
struct Channel* ChannelInit(int fd, int events, handleFunc readCallback, handleFunc writeCallback, void* arg);

// 修改fd的写事件（检测 or 不检测）
void writeEventEnable(struct Channel* channel, bool flag);

// 判断是否需要检测文件描述符的写事件
bool isWriteEventEnable(struct Channel* channel);