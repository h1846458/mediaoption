#include "Logs.h"
//#include "GetFileName.h"
#include <vector>
#include <string>
#include <fstream>  
#define OS_Linux 0
#define OS_Windows 1
#define OS_iOS 2

#if OS_S==OS_Linux
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <malloc.h>
#include <dirent.h>


#elif OS_S== OS_iOS
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#elif OS_S == OS_Windows
#include <io.h>
#include <direct.h>
#endif

std::string dumpRoot = "./cpplog"; 
std::mutex mux;
static FILE* fp = NULL;
int MaxLenChar = 1024 * 1024 * 3; // ,  1024 * 1024 * 5
int MaxLogNum = 5;

static int com(const void* a, const void* b)
{
	long long* p1, * p2;
	p1 = (long long*)a;  //
	p2 = (long long*)b;  //

	return *p1 > * p2 ? 1 : -1;
}

void GetAllFiles(std::string path, std::vector<std::string>& files)
{
	intptr_t   hFile = 0;


#if OS_S == OS_Windows
	struct _finddata_t fileinfo;//    
	std::string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)  //  
	{
		do
		{
			if ((fileinfo.attrib & _A_SUBDIR))  //  
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)  //  
				{
					files.push_back(p.assign(path).append("\\").append(fileinfo.name));
					GetAllFiles(p.assign(path).append("\\").append(fileinfo.name), files);

				}
			}
			else //   
			{


				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}

		} while (_findnext(hFile, &fileinfo) == 0);

		_findclose(hFile); //  
	}
#elif OS_S == OS_Linux


	dirent* dirt;		// linux
	DIR* dir;;
	char* s[100];
	int i = 0, n = 1;
	int onePathLen = 256;
	s[0] = new  char[onePathLen];
	memset(s[0], 0, onePathLen);
	sprintf(s[0], "%s", path.c_str());
	do {
		dir = opendir(s[i]);		//
									//
		if (dir != NULL)
		{
			while ((dirt = readdir(dir)) != NULL) {     // 
														//
				if (strcmp(dirt->d_name, ".") == 0 || strcmp(dirt->d_name, "..") == 0)
					continue;
				s[n] = new  char[onePathLen];
				memset(s[n], 0, onePathLen);
				sprintf(s[n], "%s/%s", s[i], dirt->d_name);
				n++;
			}
		}
		i++;
	} while (i < n);
	for (i = 1; i < n; i++)     // 
	{
		printf("%s\n", s[i]);

		std::string temp = s[i];
		files.push_back(temp);

	}

	closedir(dir);
	while (n--) {
		//remove(s[n]);
		delete[]s[n];
	}

#endif
}
 
void GetName(std::vector<std::string>& vPath, std::vector<std::string>& vName)
{
	if (vPath.size() <= 0)
	{
		printf("vPath.size <= 0");
		return;
	}
	for (int i = 0; i < vPath.size(); i++)
	{
		std::string path = vPath[i];

		int pointDot = path.find_last_of('.');

#if OS_S == OS_Windows
		int pointN = path.find_last_of('\\');
#elif OS_S == OS_Linux
		int pointN = path.find_last_of('/');
#endif

		std::string name = path.substr(pointN + 1, pointDot - pointN - 1);
		vName.push_back(name);
	}
}

static int removeOldFile(std::string& rootPath)
{

	std::vector<std::string> files;

	std::vector<long long> filesNum;
	GetAllFiles(rootPath, files);

	printf("rootPath = %s files.size = %d \n", rootPath.c_str(), files.size());
	if (files.size() > MaxLogNum)
	{
		for (int i = 0; i < files.size(); i++)
		{
			int pos0 = files[i].find("LOG_");

			std::string cut = files[i].substr(pos0 + 4, files[i].size());

			char* endptr = NULL;
			long long num = std::strtoll(cut.c_str(), &endptr, 10);

			printf("cut = %s num = %lld \n", cut.c_str(), num);

			filesNum.push_back(num);

		}
		qsort(&filesNum.data()[0], filesNum.size(), sizeof(long long), com);

		// 
		printf(" delete num = %d   \n", filesNum.size() - 5);
		long long deleteNum = filesNum.size() - MaxLogNum;

		for (int i = 0; i < deleteNum; i++)
		{
			std::string logPath = rootPath + std::string("/LOG_") + std::to_string(filesNum[i]);
			printf("É¾³ýÎÄ¼þ= %s   \n", logPath.c_str());
			remove(logPath.c_str());
		}
	}

	return 0;
}

int dump_init_temp() {

#undef FUNC_CODE
#define FUNC_CODE 0x01

	//create dump folder
#if OS_S==OS_Windows
	if (_access(dumpRoot.c_str(), 00) != 0) {
		_mkdir(dumpRoot.c_str());
#else
	if (access(dumpRoot.c_str(), 00) != 0) {
		mkdir(dumpRoot.c_str(), S_IRWXU);
#endif
	}
	return 0;
	}

int LOGINIT()
{

	dump_init_temp();

	removeOldFile(dumpRoot);

	long long currentMs = getCurrentMs();
	char currentMsStr[20];

	sprintf(currentMsStr, "%lld", currentMs);



	std::string logPath = dumpRoot + "/LOG_" + currentMsStr;


	fp = fopen(logPath.c_str(), "w+");
	if (fp == NULL)
	{
		return -1;
	}
	return 0;
}

int LOGSetMaxSpace(int mSize)
{
	MaxLenChar = mSize;
	return 0;
}

int logWrite(char* s)
{
	if (fp)
	{
		int len = ftell(fp);
		if (len > MaxLenChar)
		{
			LOGEnd();
			LOGINIT();
			return 0;
		}
		mux.lock();
		fprintf(fp, "%s", s);
		fflush(fp);
		mux.unlock();
	}

	return 0;
}

int LOGEnd()
{
	if (fp)
	{
		fflush(fp);
		fclose(fp);
		fp = 0;
	}
	return 0;
}

std::string getCurrentSystemTime()
{
	auto time_now = std::chrono::system_clock::now();
	auto tt = std::chrono::system_clock::to_time_t(time_now);
	auto duration_in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_now.time_since_epoch());
	auto duration_in_s = std::chrono::duration_cast<std::chrono::seconds>(time_now.time_since_epoch());
	int theMs = duration_in_ms.count() - duration_in_s.count() * 1000;
	struct tm* ptm = localtime(&tt);


	char date[60] = { 0 };
	sprintf(date, "%d-%02d-%02d-%02d.%02d.%02d.%03d%",
		(int)ptm->tm_year + 1900, (int)ptm->tm_mon + 1, (int)ptm->tm_mday,
		(int)ptm->tm_hour, (int)ptm->tm_min, (int)ptm->tm_sec, theMs);
	return std::string(date);
}

long long getCurrentMs()
{
	auto time_now = std::chrono::system_clock::now();
	auto duration_in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_now.time_since_epoch());

	return duration_in_ms.count();
}

std::string GetName(const char* fileName)
{
	char temp[256] = { 0 };
	memcpy(temp, fileName, strlen(fileName) + 1);
	std::string sName = temp;

#ifdef WIN32
	int startP = sName.find_last_of("\\");
	if (startP == -1)
	{
		startP = 0;
	}
	std::string theLastName = sName.substr(startP + 1, sName.size() - startP);

#else
	int startP = sName.find_last_of("/");
	if (startP == -1)
	{
		startP = 0;
	}
	std::string theLastName = sName.substr(startP + 1, sName.size() - startP);

#endif
	return theLastName;
}