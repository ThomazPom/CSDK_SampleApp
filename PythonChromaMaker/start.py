import colorsys
import re,struct
startFormat = "0100 0000 {typecode} {frame_count} 0000"
frameformat = " {frame_duration}{colorgrid}"

devices = {
    "Chromalink": {
        "typecode": "0000",
        "devgridlen": 1 * 5
    },
    "Headset": {
        "typecode": "0001",
        "devgridlen": 1 * 5
    },
    "Keyboard": {
        "typecode": "0100",
        "devgridlen": 6 * 22
    },
    "Keypad": {
        "typecode": "0101",
        "devgridlen": 4 * 5
    },
    "Mouse": {
        "typecode": "0102",
        "devgridlen": 9 * 7
    },
    "Mousepad": {
        "typecode": "0002",
        "devgridlen": 1 * 15
    }
}


def replace_n(string, n, first=0):
    letters = (
        # i % n == 0 means this letter should be replaced
        "\r\n" if i % n == 0 else char

        # iterate index/value pairs
        for i, char in enumerate(string, -first)
    )
    return ''.join(letters)


def hsltohex_contexted(hue):
    (r, g, b) = colorsys.hsv_to_rgb(hue, 1.0, 1.0)
    R, G, B = int(255 * r), int(255 * g), int(255 * b)

    return ' %02x%02x %02x00' % (R, G, B)

def reverse_and_space_hex(str):
    array = re.findall('..', str)
    array.reverse()
    return "{}{} {}{}".format(*array)
def float_to_hex(f):
    return hex(struct.unpack('<I', struct.pack('<f', f))[0])

def hex_float_specialformat(f):
    return reverse_and_space_hex(float_to_hex(f)[2:])

def hex_specialformat(i):
    hex_str = hex(i)
    hex_str = "0000" + hex_str[2:]
    hex_str = hex_str[-4:]
    return hex_str[-2:] + hex_str[:2]


dev_type = "Mouse"
dev_type = input("DevType in " + ", ".join(list(devices.keys())) + ": ")
frame_count = 360
frame_count = int(input("Number of frames: "))


frame_duration = 1
frame_duration = hex_float_specialformat( float(input("frames Duration: ")))

dev_props = devices.get(dev_type)
output = startFormat.format(frame_count=hex_specialformat(frame_count), typecode=dev_props.get("typecode"))
for i in range(1, frame_count + 1):
    color = hsltohex_contexted(i/frame_count)
    frame_grid = color * dev_props.get("devgridlen")
    output += frameformat.format(frame_duration=frame_duration,colorgrid=frame_grid)
output = replace_n(output, 40, 39)
#print(output + " ")
import pyperclip
pyperclip.copy(output)
print("Copied to clipboard")