#include"func.h"

void menu1()
{
	printf("**** 1. ��ӵ���*** 2. ���ҵ���  ****\n");
	printf("**** 3. ɾ������*** 4. չʾ���ʱ�****\n");
	printf("**** 5. ������  *** 6. ����      ****\n");
	printf("*****0. �˳�    *********************\n");
	printf("��ѡ��");
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
		perror("���ļ�ʧ��");
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
		printf("���ݳɹ�\n");
	}
	else
		perror("����ʧ��\n");
	tmp->cap = tmp->cap + add_cap;
}
void AddWord(wordlist* ps)
{
	if (ps->size == ps->cap)
		AddSpace(ps);
	printf("�����뵥�ʣ�");
	scanf("%s", ps->list[ps->size].character);
	printf("�����������");
	scanf("%s", ps->list[ps->size].kana);
	printf("���������ģ�");
	scanf("%s", ps->list[ps->size].chinese);
	ps->size++;
}

void ShowList(wordlist* ps)
{
	int i = 0;
	if (ps->size == NULL)
	{
		printf("���ʱ�Ϊ��\n");
		return;
	}
	else
	{
		printf("%-25s\t%-25s\t%-25s\n", "����", "����", "������˼");
		for (i = 0; i < ps->size; i++)
			printf("%-25s\t%-25s\t%-25s\n", ps->list[i].character, ps->list[i].kana, ps->list[i].chinese);
	}
}

void menu2()
{
	printf("1.ͨ�����ʲ���\n");
	printf("2.ͨ����������\n");
	printf("3.ͨ�����Ĳ���\n");
	printf("4.����\n");
}
void search1(wordlist* tmp)
{
	int i = 0;
	printf("������Ҫ���ҵĵ��ʣ�");
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
		printf("δ�ҵ����鵥�ʵļ���\n");
	else
	{
		printf("%-25s\t%-25s\t%-25s\n", "����", "����", "������˼");
		printf("%-25s\t%-25s\t%-25s\n", tmp->list[i].character, tmp->list[i].kana, tmp->list[i].chinese);
	}
}
void search2(wordlist* tmp)
{
	int i = 0;
	printf("������Ҫ���ҵĵ��ʵ����ģ�");
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
		printf("δ�ҵ����鵥��\n");
	else
	{
		printf("%-25s\t%-25s\t%-25s\n", "����", "����", "������˼");
		printf("%-25s\t%-25s\t%-25s\n", tmp->list[i].character, tmp->list[i].kana, tmp->list[i].chinese);
	}
}
void search3(wordlist* tmp)
{
	int i = 0;
	printf("������Ҫ���ҵĵ��ʣ�");
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
		printf("δ�ҵ����鵥��\n");
	else
	{
		printf("%-25s\t%-25s\t%-25s\n", "����", "����", "������˼");
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
	printf("������Ҫɾ���ĵ��ʣ�");
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
	printf("1.ͨ�����ʱ�����\n");
	printf("2.ͨ������������\n");
	printf("3.ͨ�����ı�����\n");
	printf("4.����\n");
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
		printf("������������˼(����3��ֱ�ӿ���)��");
		scanf("%s", word_tmp);
		if (0 == strcmp(ret.chinese, word_tmp))
		{
			printf("�ش���ȷ\n");
			break;
		}
	    a++;
	    if (a == 3)
		{
			printf("%-25s\t%-25s\t%-25s\n", "����", "����", "������˼");
			printf("%-25s\t%-25s\t%-25s\n", ret.character, ret.kana, ret.chinese);
			break;
		}
			printf("�ش����������\n");
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
		printf("������������˼(����3��ֱ�ӿ���)��");
		scanf("%s", word_tmp);
		if (0 == strcmp(ret.chinese, word_tmp))
		{
			printf("�ش���ȷ\n");
			break;
		}
		a++;
		if (a == 3)
		{
			printf("%-25s\t%-25s\t%-25s\n", "����", "����", "������˼");
			printf("%-25s\t%-25s\t%-25s\n", ret.character, ret.kana, ret.chinese);
			break;
		}
		printf("�ش����������\n");
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
		printf("������������˼(����3��ֱ�ӿ���)��");
		scanf("%s", word_tmp);
		if (0 == strcmp(ret.character, word_tmp))
		{
			printf("�ش���ȷ\n");
			break;
		}
		a++;
		if (a == 3)
		{
			printf("%-25s\t%-25s\t%-25s\n", "����", "����", "������˼");
			printf("%-25s\t%-25s\t%-25s\n", ret.character, ret.kana, ret.chinese);
			break;
		}
		printf("�ش����������\n");
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
		perror("���ļ�ʧ��");
		return;
	}
	static int start_save = 0;
	for (int i = start_save; i < ps->size; i++)
	{
		fwrite(&(ps->list[i]), sizeof(word), 1, pfWrite);
		printf("�ѱ���\n");
	}
	start_save = ps->size;
	fclose(pfWrite);
	pfWrite = NULL;
}