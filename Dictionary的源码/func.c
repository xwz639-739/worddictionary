#include"func.h"

void menu1()
{
	printf("**** 1. 添加单词*** 2. 查找单词  ****\n");
	printf("**** 3. 删除单词*** 4. 展示单词表****\n");
	printf("**** 5. 背单词  *** 6. 保存      ****\n");
	printf("*****0. 退出    *********************\n");
	printf("请选择：");
}
void LoadWordlist(wordlist* ps);
void AddSpace(wordlist* tmp);
void InitList(wordlist* ps)
{
	ps->list=(word* )calloc(init_cap, sizeof(word));
	if (ps->list == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->cap = init_cap;
	LoadWordlist(ps);
}
void LoadWordlist(wordlist* ps)
{
	word tmp = { 0 };
	FILE* pfRead = fopen("words_list.txt", "rb");
	if (pfRead == NULL)
	{
		perror("读文件失败");
		return;
	}
	while (fread(&tmp, sizeof(word), 1, pfRead))
	{
		if (ps->size == ps->cap)
		{
			AddSpace(ps);
		}
		ps->list[ps->size] = tmp;
		ps->size++;
	}
	fclose(pfRead);
	pfRead = NULL;
}

void AddSpace(wordlist* tmp)
{
	tmp->list = realloc(tmp->list, (tmp->cap + add_cap) * sizeof(word));
	if (tmp->list != NULL)
	{
		printf("增容成功\n");
	}
	else
		perror("增容失败\n");
	tmp->cap = tmp->cap + add_cap;
}
void AddWord(wordlist* ps)
{
	if (ps->size == ps->cap)
		AddSpace(ps);
	printf("请输入单词：");
	scanf("%s", ps->list[ps->size].character);
	printf("请输入假名：");
	scanf("%s", ps->list[ps->size].kana);
	printf("请输入中文：");
	scanf("%s", ps->list[ps->size].chinese);
	ps->size++;
}

void ShowList(wordlist* ps)
{
	int i = 0;
	if (ps->size == NULL)
	{
		printf("单词表为空\n");
		return;
	}
	else
	{
		printf("%-25s\t%-25s\t%-25s\n", "单词", "假名", "中文意思");
		for (i = 0; i < ps->size; i++)
			printf("%-25s\t%-25s\t%-25s\n", ps->list[i].character, ps->list[i].kana, ps->list[i].chinese);
	}
}

void menu2()
{
	printf("1.通过单词查找\n");
	printf("2.通过假名查找\n");
	printf("3.通过中文查找\n");
	printf("4.返回\n");
}
void search1(wordlist* tmp)
{
	int i = 0;
	printf("请输入要查找的单词：");
	char word_tmp[word_length] = { 0 };
	scanf("%s", word_tmp);
	for (i = 0; i < tmp->size; i++)
	{
		if (0 == strcmp(tmp->list[i].character, word_tmp))
		{
			break;
		}
	}
	if (i == tmp->size)
		printf("未找到所查单词的假名\n");
	else
	{
		printf("%-25s\t%-25s\t%-25s\n", "单词", "假名", "中文意思");
		printf("%-25s\t%-25s\t%-25s\n", tmp->list[i].character, tmp->list[i].kana, tmp->list[i].chinese);
	}
}
void search2(wordlist* tmp)
{
	int i = 0;
	printf("请输入要查找的单词的中文：");
	char kana_tmp[word_length] = { 0 };
	scanf("%s", kana_tmp);
	for (i = 0; i < tmp->size; i++)
	{
		if (0 == strcmp(tmp->list[i].kana, kana_tmp))
		{
			break;
		}
	}
	if (i == tmp->size)
		printf("未找到所查单词\n");
	else
	{
		printf("%-25s\t%-25s\t%-25s\n", "单词", "假名", "中文意思");
		printf("%-25s\t%-25s\t%-25s\n", tmp->list[i].character, tmp->list[i].kana, tmp->list[i].chinese);
	}
}
void search3(wordlist* tmp)
{
	int i = 0;
	printf("请输入要查找的单词：");
	char chinese_tmp[word_length] = { 0 };
	scanf("%s", chinese_tmp);
	for (i = 0; i < tmp->size; i++)
	{
		if (0 == strcmp(tmp->list[i].kana, chinese_tmp))
		{
			break;
		}
	}
	if (i == tmp->size)
		printf("未找到所查单词\n");
	else
	{
		printf("%-25s\t%-25s\t%-25s\n", "单词", "假名", "中文意思");
		printf("%-25s\t%-25s\t%-25s\n", tmp->list[i].character, tmp->list[i].kana, tmp->list[i].chinese);
	}
}
void SearchWord(wordlist* ps)
{
	int inpu;
	menu2();
	scanf("%d", &inpu);
	switch (inpu)
	{
	case 1:
		search1(ps);
		break;
	case 2:
		search2(ps);
		break;
	case 3:
		search3(ps);
		break;
	case 4:
		return;
		break;
	default:
		break;
	}
	return;
}

void DelWord(wordlist* ps)
{
	int i = 0;
	printf("请输入要删除的单词：");
	char word_tmp[word_length] = { 0 };
	scanf("%s", word_tmp);
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->list[i].character, word_tmp))
		{
			break;
		}
	}
	for (int j = i; j < ps->size-1; j++)
		ps->list[j] = ps->list[j + 1];
	ps->size--;
}

void menu3()
{
	printf("1.通过单词背中文\n");
	printf("2.通过假名背中文\n");
	printf("3.通过中文背单词\n");
	printf("4.返回\n");
}
void recite1(wordlist* tmp)
{
	int i = rand() % (tmp->size);
	printf("%s\n", tmp->list[i].character);
	int a = 0;
	word ret = tmp->list[i];
	char word_tmp[word_length];
	do
	{
		printf("请输入中文意思(错误3次直接看答案)：");
		scanf("%s", word_tmp);
		if (0 == strcmp(ret.chinese, word_tmp))
		{
			printf("回答正确\n");
			break;
		}
	    a++;
	    if (a == 3)
		{
			printf("%-25s\t%-25s\t%-25s\n", "单词", "假名", "中文意思");
			printf("%-25s\t%-25s\t%-25s\n", ret.character, ret.kana, ret.chinese);
			break;
		}
			printf("回答错误，请重试\n");
	} while (a != 3);
}
void recite2(wordlist* tmp)
{
	int i = rand() % (tmp->size);
	printf("%s\n", tmp->list[i].kana);
	int a = 0;
	word ret = tmp->list[i];
	char word_tmp[word_length];
	do
	{
		printf("请输入中文意思(错误3次直接看答案)：");
		scanf("%s", word_tmp);
		if (0 == strcmp(ret.chinese, word_tmp))
		{
			printf("回答正确\n");
			break;
		}
		a++;
		if (a == 3)
		{
			printf("%-25s\t%-25s\t%-25s\n", "单词", "假名", "中文意思");
			printf("%-25s\t%-25s\t%-25s\n", ret.character, ret.kana, ret.chinese);
			break;
		}
		printf("回答错误，请重试\n");
	} while (a != 3);
}
void recite3(wordlist* tmp)
{
	int i = rand() % (tmp->size);
	printf("%s\n", tmp->list[i].chinese);
	int a = 0;
	word ret = tmp->list[i];
	char word_tmp[word_length];
	do
	{
		printf("请输入中文意思(错误3次直接看答案)：");
		scanf("%s", word_tmp);
		if (0 == strcmp(ret.character, word_tmp))
		{
			printf("回答正确\n");
			break;
		}
		a++;
		if (a == 3)
		{
			printf("%-25s\t%-25s\t%-25s\n", "单词", "假名", "中文意思");
			printf("%-25s\t%-25s\t%-25s\n", ret.character, ret.kana, ret.chinese);
			break;
		}
		printf("回答错误，请重试\n");
	} while (a != 3);
}
void ReciteWord(wordlist* ps)
{
	int inpu;
	menu3();
	scanf("%d", &inpu);
	switch (inpu)
	{
	case 1:
		recite1(ps);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		return;
		break;
	default:
		break;
	}
}

void SaveList(wordlist* ps)
{
	FILE* pfWrite = fopen("words_list.txt", "ab");
	if (pfWrite == NULL)
	{
		perror("打开文件失败");
		return;
	}
	static int start_save = 0;
	for (int i = start_save; i < ps->size; i++)
	{
		fwrite(&(ps->list[i]), sizeof(word), 1, pfWrite);
		printf("已保存\n");
	}
	start_save = ps->size;
	fclose(pfWrite);
	pfWrite = NULL;
}