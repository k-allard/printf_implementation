// #include <stdio.h>
# include <unistd.h>
# include <stdarg.h>


size_t		ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int ft_printf(const char *s, …)
{
va_list ap;                     //Сначала нужно объявить переменную типа va_list
char *name;
unsigned int days;
va_start(ap, s);                //Затем, до обработки первого аргумента, вызвать макрос va_start, передав в него нашу переменную, а также аргумент s 
                                //(последний, идущий перед списком переменной длины)

//Затем в порядке, соответствующем строке форматирования, мы вызываем макрос va_arg столько раз, сколько у нас ожидается аргументов. Обратите внимание 
//— передается список ap, а дальше — тип аргумента (char *, unsigned int и т.д.). Важно: чтобы считать аргумент типа char, нужно передать в va_arg тип int.
name = va_arg(ap, char*);
days = va_arg(ap, unsigned int);
ft_putstr(name);
ft_putnbr(days);

// После завершения считывания аргументов необходимо вызвать макрос va_end. В модуле stdarg также доступна функция va_copy, которая позволяет сохранить состояние списка аргументов и вернуться к нему. В нашем случае в этом нет нужды.
va_end(ap);
return (0);
}

int main()
{
    char *string = "Nastya";
    unsigned int days = 28;
    ft_printf("Hello %s! The deadline is in %u days.\n", string, days);

    return 0;
}



// Задания для закрепления материала:
// Напишите функцию, которая анализирует строку форматирования и возвращает количество аргументов, которые надо будет считать дополнительно. 
// Учтите, что два идущих подряд знака процента (%%) означают, что надо напечатать сам знак процента, и аргумент в этом случае не считывается.

// Напишите функцию, которая печатает строку форматирования, а вместо каждого аргумента подставляет его номер в списке. 
// Считывать сами аргументы пока не надо, но убедитесь, что ваша функция корректно работает с разными строками (не забудьте опять про двойной знак процента).

// Напишите функцию, которая будет работать аналогично printf(), но поддерживает только преобразования %c и %s (одиночные символы и строки). 
// Флаги и модификаторы пока не обрабатываем, считаем, что аргументы задаются знаком процента, за которым сразу идет символ преобразования.

// Когда вы успешно справитесь с этими заданиями, можно будет переходить к следующей части. План предположительно таков: обрабатываем %%, %c и %s, 
// потом разбираемся с беззнаковыми целыми %u, потом учимся работать с шестнадцатеричным форматом %x и %X, на базе %x осваиваем работу с адресами %p, 
// потом перестаем бояться отрицательных чисел и работаем с %d и %i (эти два преобразования идентичны в случае printf).