import random
import os
import numpy as np
from PIL import Image

random.seed(42) # life, the universe, and randomness
img_w = 120
img_h = 120 # creates images [2*img_w, img_h]

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# GENERATE RANDOM PAIRS
#
def gen_random_pairs(n_pairs, pathin0, pathin1, pathout):
    print "gen_random_pairs"
    print "number of pairs:", n_pairs
    print "pathin0:", pathin0
    print "pathin1:", pathin1
    print "pathout:", pathout
    
    # iterate through directories to create pairs
    for x in range(n_pairs): 
        img_list = []
        path_list = []
        
        # list of image names
        img_list.append(random.choice(
            [img for img in os.listdir(pathin0)]))
        path_list.append(os.path.abspath(pathin0))
        
        # list of paths to images
        img_list.append(random.choice(
            [img for img in os.listdir(pathin1)]))
        path_list.append(os.path.abspath(pathin1))
        
        # combine images
        combo = double_images(img_list,path_list)
        
        # strip extension from first image
        name0, ext = os.path.splitext(img_list[0])
        
        # combine file names and paths and save
        filename = name0 + '.' + img_list[1]
        filename = os.path.join(pathout, filename)
        combo.save(filename)
        
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# DOUBLE IMAGES
# adapted from code on found on StackExchange: 
# <https://stackoverflow.com/questions/30227466/combine-several-
# images-horizontally-with-python>
#
def double_images(names, paths):
    images = []
    images.append(Image.open(os.path.join(paths[0],names[0])))
    images.append(Image.open(os.path.join(paths[1],names[1])))
    img = np.hstack((np.asarray(i.resize([img_w,img_h])) for i in images))
    combo = Image.fromarray(img)
    return combo
