class PGMImage{
public:
	PGMImage(const char * &);
	PGMImage();
	~PGMImage();
	bool write(const char * &);
	PGMImage * gaussian(int );
	PGMImage * convolve(float *, int size);
	void setImage( int **, int, int, int);

	//members
	int ** image;
	int w,h,q;
	float * gM;
};