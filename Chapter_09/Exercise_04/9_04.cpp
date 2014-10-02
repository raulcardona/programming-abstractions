//	Black pixels have the value true; white pixels are false.
// This function fills white pixels with black.


void fillRegion(Grid<bool> &pixels, int row, int col) {
	if (!pixels[row][col]) {
		pixels[row][col] = true;
		fillRegion(pixels, row - 1, col);
		fillRegion(pixels, row + 1, col);
		fillRegion(pixels, row, col - 1);
		fillRegion(pixels, row, col + 1);
	}
}