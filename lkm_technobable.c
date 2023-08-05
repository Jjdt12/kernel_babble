#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/random.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("James Tully");
MODULE_DESCRIPTION("It puts Star Trek technobabble in your logs.");
MODULE_VERSION("0.01");

static int __init lkm_technobabble_init(void) {

    unsigned int numbers[4] = {0, 0, 0, 0};

    int i;
    for (i = 0; i < 4; i++){
	    get_random_bytes(&numbers[i], sizeof numbers[i]);
	    numbers[i] = 0u + (numbers[i] % 5u);
    }

    char *first_word[6] = {"Realign the", "Fluctuate the", "De-frag the", "Unclog the", "Recalibrate the", "Decouple the"};
    char *second_word[6] = {"harmonic", "optronic", "auxiliary", "multi-spacial", "primary", "asymmetrical"};
    char *third_word[6] = {"sensor", "fusion", "resonance", "torsional", "gear", "gas"};
    char *fourth_word[6] = {"array", "matrix", "modulator", "core", "assembly", "manifold"};

    printk(KERN_INFO "%s %s %s %s!\n", first_word[numbers[0]], second_word[numbers[1]], third_word[numbers[2]], fourth_word[numbers[3]]);

 return 0;
}

static void __exit lkm_technobabble_exit(void) {
 printk(KERN_INFO "Computer, end program.\n");
}

module_init(lkm_technobabble_init);
module_exit(lkm_technobabble_exit);
