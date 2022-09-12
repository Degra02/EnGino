from imageio import get_writer
from PIL import Image
import numpy as np
from subprocess import Popen, DEVNULL
from pathlib import Path
from os import listdir, remove, stat, mkdir, chdir
from os.path import exists
from time import sleep

ENGINE_PATH = Path("/home/degra/Coding/C++/EnGino/PhysicsEngine")
IMAGE_PATH = Path("/tmp/engino")

chdir(ENGINE_PATH.parent)

if not exists(IMAGE_PATH):
    mkdir(IMAGE_PATH)

writer = get_writer("test.mp4", fps=60)


def pil2numpy(img: Image) -> np.ndarray:
    """
    Convert an HxW pixels RGB Image into an HxWx3 numpy ndarray
    """
    if img is None:
        raise TypeError

    return np.asarray(img)


proc = Popen([ENGINE_PATH], stdin=DEVNULL, stderr=DEVNULL, stdout=DEVNULL)

while proc.poll() is None:
    images = listdir(IMAGE_PATH)
    images.sort()
    for image in images:
        while stat(IMAGE_PATH / image).st_size != 4500054:
            sleep(.05)
        writer.append_data(pil2numpy(Image.open(IMAGE_PATH / image)))
        remove(IMAGE_PATH / image)
writer.close()
