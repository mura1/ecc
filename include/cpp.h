

typedef unsigned int token_type_t;
typedef unsigned int offset_t;
typedef unsigned int len_t;

struct token {
	unsigned int 	offset;
	unsigned int	len;	
	unsigned int	line;
};

struct value {
	struct value 	*parent;
	unsigned int 	data[2];	
};

struct tvalue {
	struct token 	token;
	struct value	value;
};

struct action {
	int (*func)(void *);
	void *data;
};
