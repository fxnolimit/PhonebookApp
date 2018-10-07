You	are	asked	to	write	a	simple	C++	phonebook	application	program.	Here	are	the	requirements	for	the	application.

  • read	the	contact	information	from	a	given	input	file	(phonebook.txt)	into	a	dynamically	created	array	of	Contact	objects.	Each	line	of	the	input	line	includes	name	and	phone	information	of	a	contact.	
  
  • Allow	to	perform	operations	on	array	of	data	such	as	search	for	a	person,	create	a	new	contact	or	delete	an	existing	contact
  
  • Make	sure	you	implemented	at	least	one	operator	overloading	and	friend	function	in	your	solution.	 	
A	sample	run:	 	 

***MY	PHONEBOOK	APPLICATION***	

Please	choose	an	operation:	
A(Add)	|	S	(Search)	|	D(Delete)	|L(List)	|Q(Quit):	A	

Enter	name:	MARY	SMITH		
Enter	phone:	5062396	

A(Add)	|	S	(Search)	|	D(Delete)	|L(List)	|Q(Quit):	S	

Enter	name:	MARY	SMITH	
Phone	Number:	5062396	 	 

A(Add)	|	S	(Search)	|	D(Delete)	|L(List)	|Q(Quit):	L	

BARBARA	BROWN	4059171	
ELIZABETH	JONES	2736877	
LINDA	WILLIAMS	3532665	
PATRICIA	JOHNSON	973437	
…	 	 

A(Add)	|	S	(Search)	|	D(Delete)	|L(List)	|Q(Quit):	D	

Enter	name:	LINDA	WILLIAMS	 	 

A(Add)	|	S	(Search)	|	D(Delete)	|L(List)	|Q(Quit):	L	

BARBARA	BROWN	4059171	
ELIZABETH	JONES	2736877	
PATRICIA	JOHNSON	973437	
…	

A(Add)	|	S	(Search)	|	D(Delete)	|L(List)	|Q(Quit):	Q	
