#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/hid.h>
#include <linux/usb/input.h>

#define DRIVER_VERSION "1.0"
#define DRIVER_AUTHOR "Inqognitoo <alexinq6@gmail.com>"
#define DRIVER_DESC "USB HID Boot Protocol Keyboard module"

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_LICENSE("GPL");

static int usbkeyboard_probe(struct usb_interface* intf, const struct usb_device_id* id)
{
    return 0;
}

static void usbkeyboard_disconnect(struct usb_interface *intf)
{

}

static const struct usb_device_id usbkeyboard_id_table[] = {
    { USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID, USB_INTERFACE_SUBCLASS_BOOT, USB_INTERFACE_PROTOCOL_KEYBOARD) },
	{}
};

MODULE_DEVICE_TABLE(usb, usbkeyboard_id_table);

static struct usb_driver usbkeyboard_driver = {
    .name = "usbkeyboard",
    .probe = usbkeyboard_probe,
    .disconnect = usbkeyboard_disconnect,
    .id_table = usbkeyboard_id_table,
};

module_usb_driver(usbkeyboard_driver);