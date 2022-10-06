#pragma once
// 初始化用于监听的套接字
int initListenfd(unsigned short port);

// 启动多路复用（epoll）
int epollRun(int lfd);

// 与客户端建立连接
// int acceptClient(int lfd, int epfd);
void* acceptClient(void* arg);

// 接收http请求
// int recvHttpRequest(int cfd, int epfd);
void* recvHttpRequest(void* arg);

// 解析请求行
int parseRequestLine(const char* line, int cfd);

// 发送文件
int sendFile(const char* fileName, int cfd);

// 发送响应头（状态行+响应头）
int sendHeadMsg(int cfd, int status, const char* descr, const char* type, int length);

// 获取文件格式，比如.jpg等
const char* getFileType(const char* name);

// 发送目录
int sendDir(const char* dirName, int cfd);

// 解码
int hexToDec(char c);
void decodeMsg(char* to, char* from);
