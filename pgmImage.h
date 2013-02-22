class PGMImage{
public:
	PGMImage(const char * &);
	PGMImage();
	~PGMImage();
	bool write(const char * &);
	PGMImage * gaussian(int );

	//members
	int ** image;
	int w,h,q;
};