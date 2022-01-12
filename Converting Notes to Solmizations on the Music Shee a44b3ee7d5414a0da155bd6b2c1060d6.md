# Converting Notes to Solmizations on the Music Sheet with Template Matching Method

Name : 武敬祥 

ID : b06611032

# Abstract

Inspired by a powerful sheet music recognition app -  notation scanner. In order to help people who aren't good at fast reading sheet music, this article describe the implementation details of OMR(optical musical recognition) technique, which can be applied to converting notes on the sheet music to solmization. Additionally, a user interface also be designed for conveniently converting.

# Introduction

To achieve the purpose of music sheet converting. A technique will be introduced -OMR OMR is an abbreviation of optical music recognition. Nowadays, there are two frameworks to implement OMR - General and Refined. Both of them incorporate four steps to achieve the converting goal. General incorporates staff line identification, musical objects located, musical feature classification, musical semantics. The refined incorporates preprocessing, music symbols recognition, musical notation reconstruction, final representation construction. The two methods are similar and, in this paper, I will only implement the general one. At the same time, I will take the worldwide well-known song - ***An die Freude*** to test and validate my algorithm.

The structure of this article is designed as follows: Section 2 introduces the objective of this paper. In section 3, some functions of the UI will be instructed in this section. Section 4 will introduce the general OMR method implementation in detail. Section 5 provides summaries and conclusions of this paper.

# Objective

- Converting notes on the sheet music to solmization to help people who aren't good at fast reading sheet music
- Creating a user interface to make people achieve the converting without effort

# User Interface

![UI.jpg](Converting%20Notes%20to%20Solmizations%20on%20the%20Music%20Shee%20a44b3ee7d5414a0da155bd6b2c1060d6/UI.jpg)

figure {} show our user interface. When opening an image, the image will show on the “Image” box. Transformation area offers the functions of selecting transformation area, canceling the selecting area. If you don’t like the transformation image, pressing “Restore” button to restore to the original image. In Solmization Conversion area, pressing “Convert” to convert notes to the solmizations and “Clear” button offer a option to clear all image. Once pressing “Convert” button, the image with note points will show up ,and he note point is marked with red point, which is not so conspicuous. Finally, the Solmizations area will show the solmizations we convert from the sheet music. figure {} shows the conversion result.

![Untitled](Converting%20Notes%20to%20Solmizations%20on%20the%20Music%20Shee%20a44b3ee7d5414a0da155bd6b2c1060d6/Untitled.png)

# Method

### Preprocessing

The preprocessing are as follows:

1. Perspective Transformation
2. Noise Removal
3. Binarization

First, the perspective transformation prevent sheet music from askew situation. Secondly, noise removal is a common image preprocessing, and, in this article, a 3 x 3 gaussian filter is adopted.  The last one is binarization.

![Preprocessing.jpg](Converting%20Notes%20to%20Solmizations%20on%20the%20Music%20Shee%20a44b3ee7d5414a0da155bd6b2c1060d6/Preprocessing.jpg)

### Staffline Identification

After the preprocessing, we get a binary and noise-removal sheet music image. Next, we want to recognize the lines of this staff. By acquiring the information of these lines, we can generate the music sheet without the staff lines or get the coordinates of the lines for musical object location. the most widely used method for detecting stafflines is based on horizontal projections(ref). This is a technique that maps a two-dimensional binary image to a one-dimensional histogram by recording the black pixels in each row of the binary image. figure {} shows the result. 

![Binary.jpg](Converting%20Notes%20to%20Solmizations%20on%20the%20Music%20Shee%20a44b3ee7d5414a0da155bd6b2c1060d6/Binary.jpg)

![Horizontal_Projection.jpg](Converting%20Notes%20to%20Solmizations%20on%20the%20Music%20Shee%20a44b3ee7d5414a0da155bd6b2c1060d6/Horizontal_Projection.jpg)

Under such projection, it is easy to find that the peaks of the histogram are where staff lines are. In the meantime, we can separate the staff lines from the sheet music and get the following two image : 

![Line_Removed.jpg](Converting%20Notes%20to%20Solmizations%20on%20the%20Music%20Shee%20a44b3ee7d5414a0da155bd6b2c1060d6/Line_Removed.jpg)

![Stafflines.jpg](Converting%20Notes%20to%20Solmizations%20on%20the%20Music%20Shee%20a44b3ee7d5414a0da155bd6b2c1060d6/Stafflines.jpg)

these two images will come in handy when we are in the task of Musical Object Located and Musical Semantics.

### Musical Objects Located

we use the pattern recognition technique - template matching to achieve the task of musical objects location. figure {} is a quarter note template we use.

![template_note2.jpg](Converting%20Notes%20to%20Solmizations%20on%20the%20Music%20Shee%20a44b3ee7d5414a0da155bd6b2c1060d6/template_note2.jpg)

In this case, we only apply the template matching technique with one template so that we can only locate the quarter notes on the sheet music.  figure{} shows the result of sheet music after the template matching :

![Template_Matching.jpg](Converting%20Notes%20to%20Solmizations%20on%20the%20Music%20Shee%20a44b3ee7d5414a0da155bd6b2c1060d6/Template_Matching.jpg)

The more white area shows the more probability that the template may locate. Then, we binarize th e figure {} and get the figure{}. Now, we can get the approximate location of the quarter note. 

![Template_Matching_Binary.jpg](Converting%20Notes%20to%20Solmizations%20on%20the%20Music%20Shee%20a44b3ee7d5414a0da155bd6b2c1060d6/Template_Matching_Binary.jpg)

The next step is to find the specific location of the quarter note. figure {} shows the the zoom-in red-bounding box 

![Template_Matching_Binary_Box.jpg](Converting%20Notes%20to%20Solmizations%20on%20the%20Music%20Shee%20a44b3ee7d5414a0da155bd6b2c1060d6/Template_Matching_Binary_Box.jpg)

![Box.jpg](Converting%20Notes%20to%20Solmizations%20on%20the%20Music%20Shee%20a44b3ee7d5414a0da155bd6b2c1060d6/Box.jpg)

![Box_Center.jpg](Converting%20Notes%20to%20Solmizations%20on%20the%20Music%20Shee%20a44b3ee7d5414a0da155bd6b2c1060d6/Box_Center.jpg)

There is a connected component composed of many white pixels.  The central idea of getting a specific location is to find the center of this connected component. Like the figure{} shows. First , we  traverse the whole image. When encountering a white pixel, we record the value, x coordinate and y coordinate of this pixel and turn it to a black pixel. Secondly, checking the four adjacent pixels of this pixel. If a white pixel exists, then repeat the step 1. It doesn't  stop until the every white pixel in this connected component is found. Thirdly, we sum up all of the x and y coordinate and calculate their average x and y, which is also the average x and y of this connected component. Finally, after traversing the whole image, we get the specific location of the quarter note in the music sheet. figure {} shows the quarter note location with red points.

![Note_Point.jpg](Converting%20Notes%20to%20Solmizations%20on%20the%20Music%20Shee%20a44b3ee7d5414a0da155bd6b2c1060d6/Note_Point.jpg)

### Musical Semantics

Now, we can get the location of the note and the location of the stafflines from “Musical Objects Located” and “Stafflines Identification”. Next, we can get the solmization with the following coding method:

![Untitled](Converting%20Notes%20to%20Solmizations%20on%20the%20Music%20Shee%20a44b3ee7d5414a0da155bd6b2c1060d6/Untitled%201.png)

 If the note is located between any interval, we encode it with the correspondent solmization. The ***An die Freude*** after solmization conversion is shown in the figure {}

![Semantics.jpg](Converting%20Notes%20to%20Solmizations%20on%20the%20Music%20Shee%20a44b3ee7d5414a0da155bd6b2c1060d6/Semantics.jpg)

# Summary and Conclusion

![OMR_Flow.jpg](Converting%20Notes%20to%20Solmizations%20on%20the%20Music%20Shee%20a44b3ee7d5414a0da155bd6b2c1060d6/OMR_Flow.jpg)

figure {} is the OMR flow chart we implement in this article. We get the solmization in the end, however, there are still a lot of defects in this algorithm. First, there are some limitations of template matching, for example, if the matching target tilts or has a different size with the template, the template matching algorithm will crash drastically. Second, an inadequate binary value may pose a big trouble in line identification. On the other hand, in this article, we only use one template so that the half note doesn't be recognized. These defects need to be improved in the future.

# Reference

- Bainbridge, David & Bell, Timothy. (2001). The Challenge of Optical Music Recognition. Computers and the Humanities. 35. 95-121. 10.1023/A:1002485918032.
- Rebelo, Ana; Fujinaga, Ichiro; Paszkiewicz, Filipe; Marcal, Andre R.S.; Guedes, Carlos; Cardoso, Jamie dos Santos (2012). ["Optical music recognition: state-of-the-art and open issues"](https://link.springer.com/content/pdf/10.1007%2Fs13735-012-0004-6.pdf)
- Pacha, Alexander; Hajič, Jan jr.; Calvo-Zaragoza, Jorge (2018). ["A Baseline for General Music Object Detection with Deep Learning"](https://doi.org/10.3390%2Fapp8091488).