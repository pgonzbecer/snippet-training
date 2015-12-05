// Created by Paul Gonzalez Becerra

// Methods first called when the app has started
/*
// Main for the HashTable
void main()
{
	// Variables
	int	tsize=	200;
	int	items[2];
	bool	bValMatch;
	HashTable	table=	HashTable(tsize);

	srand(time(0));

	for(int i= 0; i< tsize; i++)
	{
		items[0]=	(i+rand())%tsize;
		items[1]=	(rand())%tsize;
		cout<< "Key: "<< items[0]<< "; Val: "<< items[1]<< "\n";
		table.add(items[0], items[1]);
	}

	do
	{
		cout<< "Locate value given the key; type any letters to escape\n> ";
		bValMatch=	(cin>> items[0]);

		if(bValMatch)
			cout<< "Key: "<< items[0]<< ", Val: "<< table.get(items[0])<< "\n";
	}while(bValMatch);
}*/

// End of File