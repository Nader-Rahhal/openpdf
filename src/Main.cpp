#include <iostream>

#include <Main.hpp>
#include <filesystem>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

#include "poppler/cpp/poppler-document.h"


int main(int argc, char **argv) {
    poppler::document *doc = nullptr;

    if (argc > 1) {

        std::filesystem::path pdf_path(argv[1]);

        if (!std::filesystem::exists(pdf_path)) {
            std::cerr << "Error: file does not exist: " << pdf_path << "\n";
            return 1;
        }

        if (!std::filesystem::is_regular_file(pdf_path)) {
            std::cerr << "Error: path is not a regular file: " << pdf_path << "\n";
            return 1;
        }

        doc = poppler::document::load_from_file(pdf_path.string());
        if (!doc) {
            std::cerr << "Error: failed to load PDF: " << pdf_path << "\n";
            return 1;
        }

        std::cout << "Loaded PDF: " << pdf_path << "\n";
    }
    else {
        std::cerr << "Usage: " << argv[0] << " <pdf-file>\n";
        return 1;
    }
    Fl_Window *window = new Fl_Window(300,180);
    Fl_Box *box = new Fl_Box(20,40,260,100,"Hello, World!");
    box->box(FL_UP_BOX);
    box->labelsize(36);
    box->labelfont(FL_BOLD+FL_ITALIC);
    box->labeltype(FL_SHADOW_LABEL);
    window->end();
    window->show(argc, argv);
    return Fl::run();
}