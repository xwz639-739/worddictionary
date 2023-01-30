#include"function.h"

int main()
{
	srand((unsigned int)time(NULL));
	word_info word_list;
	InitWord_list(&word_list);
	int a=0;
     do
	 {
	  menu0();
	  scanf_s("%d", &a);
		switch (a)
		{
		case ADD:
			AddWords(&word_list);
			break;
		case SEARCH:
			SearchWord(&word_list);
			break;
		case RECITE:
			ReciteWords(&word_list);
			break;
		case SHOW:
			ShowWordlist(&word_list);
			break;
		case SAVE:
			SaveWordlist(&word_list);
			break;
		case EXIT:
			SaveWordlist(&word_list);
			Destroy(&word_list);
			printf("已退出\n");
			break;
		default:
			printf("无效输入\n");
			break;
		}
		
     }while (a);
	return 0;
}