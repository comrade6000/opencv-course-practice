#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int main ( )

{

Mat src = imread ( "1984-big-brother.png", 1 );
Mat dst;
Mat gray, edge;

imshow ( "src00", src );

//median filter
medianBlur ( src, dst, 35 );
imshow ( "rlt0_median", dst ); 
	 
//bilateralFilter
bilateralFilter ( src, dst, 25, 90, 90 );
imshow ( "rlt1_bilateral", dst );  

//GaussianBlur
GaussianBlur ( src, dst, Size ( 35, 35), 0, 0 );
imshow ( "rlt2_Gaussian", dst );
	 
//blur
blur ( src, dst, Size (13, 13 ) );
imshow ( "rlt3_blur", dst );

//cany image
cvtColor ( src, dst, CV_BGR2GRAY );
Canny ( dst, edge, 150, 200, 3 );
edge.convertTo ( dst, CV_8U );
imshow ( "rlt4_canny", dst );
	 
//equalizeHist
cvtColor ( src, gray, CV_BGR2GRAY );
equalizeHist ( gray, dst );
imshow ( "rlt5_equalizeHist", dst );

waitKey ( 0 );
return 0;

}

