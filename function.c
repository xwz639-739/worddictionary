#include"function.h"



void menu0()
{
	printf("1. 输入单词\n");
	printf("2. 查单词\n");
	printf("3. 背单词(尚未完善)\n");
	printf("4. 展示单词\n");
	printf("5. 保存\n");
	printf("0. 退出\n");
}
void menu1()
{
	printf("1. 看单词背中文意思\n");
	printf("2. 看假名背中文意思\n");
	printf("3. 看中文意思背单词\n");
	printf("4. 看中文意思背假名\n");
	printf("0. 退出\n");
	printf("请选择模式：");
}
void SaveWordlist(word_info* ps)
{
	FILE* pfWrite = fopen("words_list.txt", "ab");
	if (pfWrite == NULL)
	{
		perror("打开文件失败");
		return;
	}
	static int start_save = 0;
	for (int i=start_save; i < ps->num; i++)
	{
		fwrite(&(ps->sigle_word[i]), sizeof(words), 1, pfWrite);
		printf("已保存\n");
	}
	start_save = ps->num;
	fclose(pfWrite);
	pfWrite = NULL;
}
void AddSpace(word_info* ps)
{
	words* ret = realloc(ps->sigle_word, (ps->cap + 5) * sizeof(words));
	if (ret != NULL)
	{
		printf("增容成功\n");
	}
	else
		perror("增容失败\n");
}
void LoadWordlist(word_info* ps);
void InitWord_list(word_info* ps)
{
	ps->sigle_word = (words*)calloc(5, sizeof(words));
	if (ps->sigle_word == NULL)
	{
		return;
	}
	ps->num = 0;
	ps->cap = 5;
	LoadWordlist(ps);
}
void LoadWordlist(word_info* ps)
{
	words tmp = { 0 };
	FILE* pfRead = fopen("words_list.txt", "rb");
	if (pfRead == NULL)
	{
		perror("读文件失败");
		return;
	}
	while (fread(&tmp, sizeof(words), 1, pfRead))
	{
		if (ps->num == ps->cap)
		{
			SaveWordlist(ps);
			AddSpace(ps);
		}
		ps->sigle_word[ps->num] = tmp;
		ps->num++;
	}
	//fclose(pfRead);
	//pfRead = NULL;
}


void AddWords(word_info* ps)
{
	system("cls");
	if (ps->num == ps->cap)
	{
		SaveWordlist(ps);
		AddSpace(ps);
	}
		printf("请输入单词：");
		scanf("%s", ps->sigle_word[ps->num].word);
		printf("请输入假名：");
		scanf("%s", ps->sigle_word[ps->num].kana);
		printf("请输入中文意思：");
		scanf("%s", ps->sigle_word[ps->num].Chinese);

		ps->num ++;
		printf("添加成功\n");
}

void ShowWordlist(const word_info* ps)
{
	system("cls");
	int i = 0;
	if (ps->num == NULL)
	{
		printf("单词表为空\n");
		return;
	}
	else
	{
		printf("%-30s\t%-30s\t%-30s\n", "单词", "假名", "中文意思");
		for (i = 0; i < ps->num; i++)
		{
			printf("%-30s\t%-30s\t%-30s\n", 
				ps->sigle_word[i].word,
				ps->sigle_word[i].kana,
				ps->sigle_word[i].Chinese);
		}
	}
}

void SearchWord(const word_info* ps)
{
	system("cls");
	int i = 0;
	printf("请输入要查找的单词：");
	char word_tmp[LENGTH] = {0};
	scanf("%s", word_tmp);
	for ( i= 0; i < ps->num; i++)
	{
		if (0 == strcmp(ps->sigle_word[i].word, word_tmp))
		{
			break;
		}
	}
	if (i == ps->num)
		printf("未找到所查单词\n");
	else
	{
		printf("%-30s\t%-30s\t%-30s\n", "单词", "假名", "中文意思");
		printf("%-30s\t%-30s\t%-30s\n",
			ps->sigle_word[i].word,
			ps->sigle_word[i].kana,
			ps->sigle_word[i].Chinese);
	}
}

void recite1(const word_info* tmp)
{
	system("cls");
	int a = 1;
	int i = rand() % tmp->num + 1;
	printf("%s\n", tmp->sigle_word[i].word);
	while (a)
	{
		printf("请输入中文意思(输入DK直接看答案)：");
		char word_tmp[LENGTH];
		scanf("%s", word_tmp);
		for (i = 0; i < tmp->num; i++)
		{
			if (strcmp(word_tmp, "DK"))
			{
				printf("%-30s\t%-30s\t%-30s\n", "单词", "假名", "中文意思");
				printf("%-30s\t%-30s\t%-30s\n",
					tmp->sigle_word[i].word,
					tmp->sigle_word[i].kana,
					tmp->sigle_word[i].Chinese);
				a = 0;
				break;
			}
			else if (0 == strcmp(tmp->sigle_word[i].Chinese, word_tmp))
			{
				break;
			}
		}
		if (i == tmp->num)
			printf("回答错误，请重试\n");
	    
		else if(a != 0)
		{
			printf("回答正确！\n");
			a = 0;
			break;
		}
	}
}
void recite2(const word_info* tmp)
{
	system("cls");
	int a = 1;
	int i = rand() % tmp->num + 1;
	printf("%s\n", tmp->sigle_word[i].kana);
	while (1)
	{
		printf("请输入中文意思(输入DK直接看答案)：");
		char word_tmp[LENGTH];
		scanf("%s", word_tmp);
		for (i = 0; i < tmp->num; i++)
		{
			if (strcmp(word_tmp, "DK"))
			{
				printf("%-30s\t%-30s\t%-30s\n", "单词", "假名", "中文意思");
				printf("%-30s\t%-30s\t%-30s\n",
					tmp->sigle_word[i].word,
					tmp->sigle_word[i].kana,
					tmp->sigle_word[i].Chinese);
				a = 0;
				break;
			}
			else if (0 == strcmp(tmp->sigle_word[i].Chinese, word_tmp))
			{
				break;
			}
		}
		if (i == tmp->num)
			printf("回答错误，请重试\n");
		
		else if(a != 0)
		{
			printf("回答正确！\n");
			a = 0;
			break;
		}
	}
}
void recite3(const word_info* tmp)
{
	system("cls");
	int a = 1;
	int i = rand() % tmp->num + 1;
	printf("%s\n", tmp->sigle_word[i].Chinese);
	while (1)
	{
		printf("请输入单词(输入DK直接看答案)：");
		char word_tmp[LENGTH];
		scanf("%s", word_tmp);
		for (i = 0; i < tmp->num; i++)
		{
			if (strcmp(word_tmp, "DK"))
			{
				printf("%-30s\t%-30s\t%-30s\n", "单词", "假名", "中文意思");
				printf("%-30s\t%-30s\t%-30s\n",
					tmp->sigle_word[i].word,
					tmp->sigle_word[i].kana,
					tmp->sigle_word[i].Chinese);
				a = 0;
				break;
			}
			else if (0 == strcmp(tmp->sigle_word[i].word, word_tmp))
			{
				break;
			}
		}
		if (i == tmp->num)
			printf("回答错误，请重试\n");
		else if(a != 0)
		{
			printf("回答正确！\n");
			a = 0;
			break;
		}
	}
}
void recite4(const word_info* tmp)
{
	system("cls");
	int a = 1;
	int i = rand() % tmp->num + 1;
	printf("%s\n", tmp->sigle_word[i].Chinese);
	while (1)
	{
		printf("请输入中文意思(输入DK直接看答案)：");
		char word_tmp[LENGTH];
		scanf("%s", word_tmp);
		for (i = 0; i < tmp->num; i++)
		{
			if (strcmp(word_tmp, "DK"))
			{
				printf("%-30s\t%-30s\t%-30s\n", "单词", "假名", "中文意思");
				printf("%-30s\t%-30s\t%-30s\n",
					tmp->sigle_word[i].word,
					tmp->sigle_word[i].kana,
					tmp->sigle_word[i].Chinese);
				a = 0;
				break;
			}
			else if (0 == strcmp(tmp->sigle_word[i].kana, word_tmp))
			{
				break;
			}
		}
		if (i == tmp->num)
			printf("回答错误，请重试\n");
	    
		else if(a != 0)
		{
			printf("回答正确！\n");
			a = 0;
			break;
		}
	}
}
void ReciteWords(const word_info* ps)
{
	int choose = 0;
	system("cls");
	do
	{
		menu1();
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			recite1(ps);
			break;
		case 2:
			recite2(ps);
			break;
		case 3:
			recite3(ps);
			break;
		case 4:
			recite4(ps);
			break;
		case 0:
			printf("已退出\n");
			break;
		default:
			printf("无该项选择，请重试。");
			break;
		}
	} while (choose);
}

void Destroy(word_info* ps)
{
	free(ps->sigle_word);
	ps->sigle_word = NULL;
}

