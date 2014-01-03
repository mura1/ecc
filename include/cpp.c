

typedef unsigned int token_type_t;
typedef unsigned int offset_t;
typedef unsigned int len_t;

struct token {
	unsigned int 	offset;
	unsigned int	len;	
	unsigned int	line;
	unsigned int	line_offset;
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

typedef int (*matcher_t)(struct tvalue *tv, char *s);






int match_decimal(struct tvalue *tv, char *)
{
	return 0;
}

static matcher_t default_matcher_list[] = {
	match_decimal,
	(void *)0,
};

int run_matchers(struct tvalue *tv, struct matcher_t *m, unsigned int m_count, char *s)
{
	int i, ret = -1;

	for (i = 0; i < m_count; i++) {
		if ((ret = m(tv, s)) ==  0)
			break;
	}
	return ret;
}






int main(int argc, char **argv)
{
	return 0;
}
