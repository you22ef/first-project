// FCI – Programming 1 – 2022 - Assignment 3
// Program Name: CS112–S10-20210210-20210014-20210484-A3-FULL.cpp
// Last Modification Date: 04/07/2022
// Author1 and ID and Group: Ahmed Hanafy Bekheet - 20210014 - S10
// Author2 and ID and Group: Abdelrhman Mostafa Hessain - 20210210 - S10
// Author3 and ID and Group: Youssef Mohammed Atya - 20210484 - S10
// Teaching Assistant: Afaf Abdelmonem
// Purpose: Edit grayscale photo and add filter to it.

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];
char userInput;


// declare every function that we are going to use later
void menuDisplay();
void loadImage();
void saveImage();
void BW();
void invertFilter();
void mergeImage();
void flipImage();
void rotate();
void darkenAndLightenImage();
void detect_edge();
void enlargeImage();
void shrinkImage();
void mirror();
void shuffleImage();
void blur();




int main()
{
    cout << "Ahlan ya user ya habibi\n";
    loadImage();
    while (true) { // To loop till the user Exit the program
        menuDisplay();
        switch (userInput)
        {
        case 48: // if userInput == 0 exit
            cout << "Thanks for using fcai photoshop :)";
            return 0;
        case 49:
            BW();
            break;
        case 50:
            invertFilter();
            break;
        case 51:
            mergeImage();
            break;
        case 52:
            flipImage();
            break;
        case 53:
            rotate();
            break;
        case 54:
            darkenAndLightenImage();
            break;
        case 56:
            enlargeImage();
            break;
        case 55:
            BW();
            detect_edge();
            break;
        case 57:
            shrinkImage();
            break;
        case 97:
            mirror();
            break;
        case 98:
            shuffleImage();
            break;
        case 99:
            blur();
            break;
        case 115:
            saveImage();
            break;
        }
    }
}

//_________________________________________
void menuDisplay() {

    cout << "Please select a filter to apply or 0 to exit: \nNote: The Answer Is Only One Char 'The App Will Take Only First Char'\n";
    while (true) { // To take the user input again if not valid
        cout << "\t1- Black & White Filter" << endl;
        cout << "\t2- Invert Filter" << endl;
        cout << "\t3- Merge Filter" << endl;
        cout << "\t4- Flip Image" << endl;
        cout << "\t5- Rotate Image" << endl;
        cout << "\t6- Darken and Lighten Image" << endl;
        cout << "\t7- Detect Image Edges" << endl;
        cout << "\t8- Enlarge Image" << endl;
        cout << "\t9- Shrink Image" << endl;
        cout << "\ta- Mirror 1/2 Image" << endl;
        cout << "\tb- Shuffle Image" << endl;
        cout << "\tc- Blur Image" << endl;
        cout << "\ts- save the image to file" << endl;
        cout << "\t0- Exit" << endl;
        cout << "--> ";

        cin >> userInput;
        if ((userInput >= 48 && userInput <= 57) || (userInput == 97 || userInput == 98 || userInput == 99 || userInput == 115))
            break;
        else {
            cout << "Please enter valid input from the menu!!\n\n";
            cin.ignore();
        }
    }
}
//_________________________________________
void loadImage() {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Please enter file name of the image to process: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

//_________________________________________
void saveImage() {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);

}
//_________________________________________
void BW() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) { // to make each pixel black
            if (image[i][j] > 127) {
                image[i][j] = 255;
            }
            else { // to make each pixel white
                image[i][j] = 0;
            }

        }
    }
}
//_________________________________________
void invertFilter() {
    for (int i = 0; i < SIZE; i++) { 
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = 255 - image[i][j]; // The complement of the pixel value is the invert of it
        }
    }
}
//_________________________________________
void mergeImage() {
    unsigned char image2[SIZE][SIZE];
    //Load seconde Image
    char mergedImageFileName[100];

    // Get the seconde photo that want to be merged
    cout << "Please enter file name of the image to merge: ";
    cin >> mergedImageFileName;

    // Add to it .bmp extension and load image
    strcat(mergedImageFileName, ".bmp");
    readGSBMP(mergedImageFileName, image2);

    //Merge Two Photos
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = (image[i][j] / 2) + (image2[i][j] / 2);
        }
    }
}
//_________________________________________
void flipImage() {
    unsigned char image2[SIZE][SIZE];
    int choose;
    while (true) // To take the input again if the user input is not valid
    {
        cout << "Flip (1) for horizontally or (2) for vertically: ";
        cin >> choose;
        if (choose == 1 || choose == 2) {
            break;
        }
        else {
            cout << "Invalid input.";
            cin.ignore();
        }
    }
    if (choose == 1) {
        for (int i = 0; i < 255; i++) { // To put the first column the last and the last the first
            for (int j = 255; j > 0; j--) {
                image2[i][255 - j] = image[i][j];

            }
        }
    }
    else {
        for (int i = 0; i < 255; i++) { // To put the last row the first and the last the first
            for (int j = 0; j < 255; j++) {
                image2[i][j] = image[255 - i][j];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) { // To save at image 1 to make any change again on it if the user want
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = image2[i][j];
        }
    }
}
//_________________________________________
void rotate() {
    unsigned char image2[SIZE][SIZE];
    int rot;

    while (true) { // To take the input again if the user input is not valid
        cout << "Enter the degree from (90, 180, 270) to rotate: ";
        cin >> rot;
        if (rot == 90 || rot == 180 || rot == 270)
            break;
        else {
            cout << "Please enter valid number\n";
            cin.ignore();
        }
    }
    if (rot == 90) { 
        for (int i = 0; i < SIZE; i++) { // Swap the first row with the last column
            for (int j = 0; j <= SIZE - i; j++) {
                swap(image[i][j], image[SIZE - j][SIZE - i]);
            }
        }
        for (int i = 0; i < SIZE; i++) { // To flip the image to get the rotate 90 degrees
            for (int j = 0; j < SIZE; j++) {
                image2[i][j] = image[255 - i][j];
            }
        }
    }
    else if (rot == 180) {
        for (int i = 0; i < SIZE; i++) { // To make the first column the last and make the first row the last
            for (int j = 0; j < SIZE; j++) {
                image2[i][j] = image[255 - i][255 - j];
            }
        }
    }
    else if (rot == 270) {
        for (int i = 0; i < SIZE; i++) { // Swap the first row with the last column
            for (int j = 0; j <= SIZE - i; j++) {
                swap(image[i][j], image[SIZE - j - 1][SIZE - i]);
            }
        }
        for (int i = 0; i < SIZE; i++) { // To make the first column the last
            for (int j = 0; j < SIZE; j++) {
                image2[i][j] = image[i][255 - j];
            }
        }
    }
    for (int i = 0; i < SIZE; i++) { // To save at image 1 to make any change again on it if the user want
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = image2[i][j];
        }
    }
}
//_________________________________________
void darkenAndLightenImage() {
    int chooses;
    cout << "Please Choose;" << endl;
    while (true) { // To take the input again if the user input is not valid
        cout << "\t1- Light" << endl;
        cout << "\t2- Dark" << endl;
        cout << "--> ";
        cin >> chooses;

        if (chooses == 1 || chooses == 2)
            break;
        else {
            cout << "Please choose valid input\n";
            cin.ignore();
        }
    }
    if (chooses == 1) {
        for (int i = 0; i < SIZE; i++) { // To make the photo more lighting
            for (int j = 0; j < SIZE; j++) {
                if (image[i][j] < 127)
                    image[i][j] += 127;
                else
                    image[i][j] = 255;
            }
        }
    }
    else {
        for (int i = 0; i < SIZE; i++) { // To make the photo more dark
            for (int j = 0; j < SIZE; j++) {
                image[i][j] -= 0.5 * (image[i][j]);
            }
        }
    }

}
//_________________________________________
void detect_edge() {  // We make the photo Black & white first
    for (int i = 0; i < SIZE; i++) { // Check if there is a difference between the pixel and the neighbors make the pixel black else white
        for (int j = 0; j < SIZE; j++) {
            if (image[i][j] == image[i][j + 1] && image[i][j] == image[i + 1][j] && image[i][j] == image[i + 1][j + 1]) {
                image[i][j] = 255;
            }
            else {
                image[i][j] = 0;
            }
        }
    }
}
//_________________________________________
void enlargeImage() {
    unsigned char image2[SIZE][SIZE], quarterImage[SIZE][SIZE];
    int quarter;
    int row = 0, col = 0;
    while (true) {
        cout << "Please, Enter the number of quarter" << endl;
        cout << "--> ";
        cin >> quarter;
        if (quarter == 1 || quarter == 2 || quarter == 3 || quarter == 4)
            break;
        else {
            cout << "Please, Enter Int from 1 to 4!!..\n\n";
            cin.ignore();
        }
    }
    // Create quarterImage 
    if (quarter == 1) {
        for (int i = 0; i < 127; i++) {
            for (int j = 0; j < 127; j++) {
                quarterImage[i][j] = image[i][j];
            }
        }
    }
    if (quarter == 2) {
        for (int i = 0; i < 127; i++) {
            for (int j = 127; j < 255; j++) {
                quarterImage[i][j] = image[i][j];
            }
        }
    }
    if (quarter == 3) {
        for (int i = 127; i < 255; i++) {
            for (int j = 0; j < 127; j++) {
                quarterImage[i][j] = image[i][j];
            }
        }
    }
    if (quarter == 4) {
        for (int i = 127; i < 255; i++) {
            for (int j = 127; j < 255; j++) {
                quarterImage[i][j] = image[i][j];
            }
        }
    }
    //End of creation
    if (quarter == 1) { // To put each pixel repeated at square of 2 by 2
        row = 0;
        col = 0;
        for (int i = 0; i < SIZE; i += 2) {
            for (int j = 0; j < SIZE; j += 2) {
                image2[i][j] = quarterImage[row][col];
                image2[i][j + 1] = quarterImage[row][col];
                image2[i + 1][j] = quarterImage[row][col];
                image2[i + 1][j + 1] = quarterImage[row][col];

                col++;
            }
            col = 0;
            row++;
        }

    }
    if (quarter == 2) { // To put each pixel repeated at square of 2 by 2
        row = 0;
        col = 127;
        for (int i = 0; i < SIZE; i += 2) {
            for (int j = 0; j < SIZE; j += 2) {
                image2[i][j] = quarterImage[row][col];
                image2[i][j + 1] = quarterImage[row][col];
                image2[i + 1][j] = quarterImage[row][col];
                image2[i + 1][j + 1] = quarterImage[row][col];

                col++;
            }
            col = 127;
            row++;
        }

    }
    if (quarter == 3) { // To put each pixel repeated at square of 2 by 2
        row = 127;
        col = 0;
        for (int i = 0; i < SIZE; i += 2) {
            for (int j = 0; j < SIZE; j += 2) {
                image2[i][j] = quarterImage[row][col];
                image2[i][j + 1] = quarterImage[row][col];
                image2[i + 1][j] = quarterImage[row][col];
                image2[i + 1][j + 1] = quarterImage[row][col];

                col++;
            }
            col = 0;
            row++;
        }

    }
    if (quarter == 4) { // To put each pixel repeated at square of 2 by 2
        row = 127;
        col = 127;
        for (int i = 0; i < SIZE; i += 2) {
            for (int j = 0; j < SIZE; j += 2) {
                image2[i][j] = quarterImage[row][col];
                image2[i][j + 1] = quarterImage[row][col];
                image2[i + 1][j] = quarterImage[row][col];
                image2[i + 1][j + 1] = quarterImage[row][col];
                col++;
            }
            col = 127;
            row++;
        }

    }
    for (int i = 0; i < SIZE; i++) { // To save at image 1 to make any change again on it if the user want
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = image2[i][j];
        }
    }
}
//_________________________________________
void shrinkImage() {
    unsigned char image2[SIZE][SIZE];
    int size;
    int row = 0, col = 0;
    while (true) { // To take the input again if the user input is not valid
        cout << "Please, Enter the number of size\n\t1- 1/2 size of the image.\n\t2- 1/3 size of the image.\n\t3- 1/4 size of the image." << endl;
        cout << "--> ";
        cin >> size;
        if (size == 1 || size == 2 || size == 3)
            break;
        else {
            cout << "Please, Enter Int from 1 to 3!!..\n\n";
            cin.ignore();
        }
    }
    if (size == 1) { // Take from 2-pixel one pixel only
        for (int i = 0; i < SIZE; i += 2) {
            for (int j = 0; j < SIZE; j += 2) {
                image2[row][col] = image[i][j];
                col++;
            }
            col = 0;
            row++;
        }
    }
    if (size == 2) { // Take from 3-pixel one pixel only
        for (int i = 0; i < SIZE; i += 3) {
            for (int j = 0; j < SIZE; j += 3) {
                image2[row][col] = image[i][j];
                col++;
            }
            col = 0;
            row++;
        }
    }
    if (size == 3) { // Take from 4-pixel one pixel only
        for (int i = 0; i < SIZE; i += 4) {
            for (int j = 0; j < SIZE; j += 4) {
                image2[row][col] = image[i][j];
                col++;
            }
            col = 0;
            row++;
        }
    }
    for (int i = 0; i < SIZE; i++) { // To save at image 1 to make any change again on it if the user want
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = image2[i][j];
        }
    }
}
//_________________________________________
void mirror() {
    int side, x = 0;
    while (true) { // To take the input again if the user input is not valid
        cout << "Please, Enter the number of the side\n\t1- Left\n\t2- Right\n\t3- Upper\n\t4- Lower\n";
        cout << "--> ";
        cin >> side;
        if (side == 1 || side == 2 || side == 3 || side == 4)
            break;
        else {
            cout << "Please, Enter Int from 1 to 4!!..\n\n";
            cin.ignore();
        }
    }
    if (side == 1) { // Repeat the left side at the right
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {

                if (j > (SIZE / 2)) {
                    image[i][j] = image[i][(SIZE / 2) - x];
                    x++;
                }

            }
            x = 0;
        }
    }
    else if (side == 2) { // Repeat the right side at the left side
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (j < (SIZE / 2)) {
                    image[i][j] = image[i][SIZE - x];
                    x++;
                }

            }
            x = 0;
        }
    }
    else if (side == 3) { // Repeat the upperr side at the lower
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (i > (SIZE / 2)) {
                    image[i][j] = image[SIZE - i][j];
                }
            }
        }
    }
    else if (side == 4) { // Repeat the lower side at the upper
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (i < (SIZE / 2)) {
                    image[i][j] = image[SIZE - x][j];
                }
            }
            x++;
        }
    }
}
//_________________________________________
void shuffleImage() {
    //declare vars
    unsigned char quarters[4][SIZE][SIZE], image2[SIZE][SIZE];
    int row = 0, col = 0, order[4];
    //end of declare vars

    //create quarters by 4 loops
    for (int i = 0; i < 127; i++) {
        for (int j = 0; j < 127; j++) {
            quarters[0][row][col] = image[i][j];
            col++;
        }
        row++;
        col = 0;
    }
    row = 0, col = 0;
    for (int i = 0; i < 127; i++) {
        for (int j = 127; j < 255; j++) {
            quarters[1][row][col] = image[i][j];
            col++;
        }
        row++;
        col = 0;

    }
    row = 0, col = 0;
    for (int i = 127; i < 255; i++) {
        for (int j = 0; j < 127; j++) {
            quarters[2][row][col] = image[i][j];
            col++;
        }
        row++;
        col = 0;
    }
    row = 0, col = 0;
    for (int i = 127; i < 255; i++) {
        for (int j = 127; j < 255; j++) {
            quarters[3][row][col] = image[i][j];
            col++;
        }
        row++;
        col = 0;
    }
    //end of create quarters by 4 loops 


    //take the order of photo
    cout << "Please, Enter the order of the image (e.g:4 3 2 1)\n--> ";
    for (int i = 0; i < 4; i++) {
        cin >> order[i];
    }
    //end of take the order of photo

    //create the final image
    col = 0, row = 0;
    for (int i = 0; i < 127; i++) {
        for (int j = 0; j < 127; j++) {
            image2[i][j] = quarters[order[0] - 1][row][col];
            col++;
        }
        row++;
        col = 0;
    }
    row = 0, col = 0;
    for (int i = 0; i < 127; i++) {
        for (int j = 127; j < 255; j++) {
            image2[i][j] = quarters[order[1] - 1][row][col];
            col++;
        }
        row++;
        col = 0;
    }
    row = 0, col = 0;
    for (int i = 127; i < 255; i++) {
        for (int j = 0; j < 127; j++) {
            image2[i][j] = quarters[order[2] - 1][row][col];
            col++;
        }
        row++;
        col = 0;
    }
    row = 0, col = 0;
    for (int i = 127; i < 255; i++) {
        for (int j = 127; j < 255; j++) {
            image2[i][j] = quarters[order[3] - 1][row][col];
            col++;
        }
        row++;
        col = 0;
    }
    //end of create the final image

    for (int i = 0; i < SIZE; i++) { // To save at image 1 to make any change again on it if the user want
        for (int j = 0; j < SIZE; j++) {
            image[i][j] = image2[i][j];
        }
    }
}
//_________________________________________
void blur() {
    for (int i = 0; i < SIZE; i++) { // Take the sum of the pixel and their neighbors and divide by 9
        for (int j = 0; j < SIZE; j++) {
            if (i >= 1 && j < SIZE && i < SIZE && j >= 1) {
                image[i][j] = (image[i - 1][j - 1] + image[i][j - 1] + image[i + 1][j - 1] + image[i - 1][j] + image[i][j] + image[i + 1][j] + image[i - 1][j + 1] + image[i][j + 1] + image[i + 1][j + 1]) / 9;
            }
        }
    }
}