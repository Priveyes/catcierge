#!/usr/bin/python

import numpy as np
import cv2
import sys
import os
import glob
import argparse

parser = argparse.ArgumentParser()

parser.add_argument("images", metavar="IMAGES", nargs=1,
                    help="The Catcierge match images to test.")
parser.add_argument("--threshold", "-t", type=int, default=90,
					help="The threshold value")

args = parser.parse_args()

if not os.path.exists(args.images[0]):
	print("No such file %s" % args.images[0])
	exit(-1)

img = cv2.imread(args.images[0])

if len(img) == 2:
	img_gray = img
else:
	img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
ret, threshimg = cv2.threshold(img_gray, args.threshold, 255, 0)
cv2.imwrite("thr.png", threshimg)

contours, hierarchy = cv2.findContours(threshimg, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
max_area = 0
max_contour = None
for contour in contours:
	area = cv2.contourArea(contour)
	if (area > max_area):
		max_area, max_contour = area, contour

r = cv2.boundingRect(max_contour)
print r
x, y, w, h = r
cv2.drawContours( img, contours, -1, (0, 255, 0), 3 )
cv2.rectangle(img, (x, y), (x + w, y + h), (0, 0, 255), 3)

cv2.imwrite("sq.png", img)

