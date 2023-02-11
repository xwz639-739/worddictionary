#include"func.h"

int main()
{
	int input = 0;
	wordlist List;
	InitList(&List);
	srand((unsigned int)time(NULL));
	do
	{
		printf("当前单词数量：%d  当前单词最大数量：%d\n", List.size, List.cap);
		menu1();
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddWord(&List);
			break;
		case SEARCH:
			SearchWord(&List);
			break;
		case DEL:
			DelWord(&List);
			break;
		case SHOW:
			ShowList(&List);
			break;
		case RECITE:
			ReciteWord(&List);
			break;
		case SAVE:
			SaveList(&List);
			break;
		case EXIT:
			SaveList(&List);
			printf("已退出\n");
			break;
		default:
			break;
		}
	} while (input);
	free(List.list);
	List.list == NULL;
	return 0;
}