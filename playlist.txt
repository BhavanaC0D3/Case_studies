#include <stdio.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct {
    char title[50];
    char artist[50];
    char genre[20];
} Song;

typedef struct {
    Song songs[MAX_SONGS];
    int count;
    int current_index;
} Playlist;

void add_song(Playlist *playlist, char *title, char *artist, char *genre) {
    if (playlist->count >= MAX_SONGS) {
        printf("Playlist is full. Cannot add more songs.\n");
        return;
    }
    strcpy(playlist->songs[playlist->count].title, title);
    strcpy(playlist->songs[playlist->count].artist, artist);
    strcpy(playlist->songs[playlist->count].genre, genre);
    playlist->count++;
    printf("Song added: %s by %s [%s]\n", title, artist, genre);
}

void play_next(Playlist *playlist) {
    if (playlist->current_index < playlist->count - 1) {
        playlist->current_index++;
        printf("Playing next song: %s by %s\n", playlist->songs[playlist->current_index].title, playlist->songs[playlist->current_index].artist);
    } else {
        printf("Already at the last song.\n");
    }
}

void play_previous(Playlist *playlist) {
    if (playlist->current_index > 0) {
        playlist->current_index--;
        printf("Playing previous song: %s by %s\n", playlist->songs[playlist->current_index].title, playlist->songs[playlist->current_index].artist);
    } else {
        printf("Already at the first song.\n");
    }
}

void switch_to_song(Playlist *playlist, int index) {
    if (index >= 0 && index < playlist->count) {
        playlist->current_index = index;
        printf("Switched to song: %s by %s\n", playlist->songs[index].title, playlist->songs[index].artist);
    } else {
        printf("Invalid song index.\n");
    }
}

void display_songs_by_genre(Playlist *playlist, char *genre) {
    printf("Songs of genre %s:\n", genre);
    int found = 0;
    int i;
    for (i = 0; i < playlist->count; i++) {
        if (strcmp(playlist->songs[i].genre, genre) == 0) {
            printf("%d. %s by %s\n", i + 1, playlist->songs[i].title, playlist->songs[i].artist);
            found = 1;
        }
    }
    if (!found) {
        printf("No songs found for this genre.\n");
    }
}

void display_current_song(Playlist *playlist) {
    if (playlist->count > 0) {
        printf("Currently playing: %s by %s\n", playlist->songs[playlist->current_index].title, playlist->songs[playlist->current_index].artist);
    } else {
        printf("No songs in the playlist.\n");
    }
}

int main() {
    Playlist playlist = {{0}, 0, 0};
    int choice;
    char title[50], artist[50], genre[20];
    int index;

    while (1) {
        printf("\n--- Music Playlist Menu ---\n");
        printf("1. Add Song\n");
        printf("2. Play Next\n");
        printf("3. Play Previous\n");
        printf("4. Switch to Song\n");
        printf("5. Display Songs by Genre\n");
        printf("6. Display Current Song\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter song title: ");
                scanf(" %[^\n]%*c", title);
                printf("Enter artist name: ");
                scanf(" %[^\n]%*c", artist);
                printf("Enter genre: ");
                scanf(" %[^\n]%*c", genre);
                add_song(&playlist, title, artist, genre);
                break;
            case 2:
                play_next(&playlist);
                break;
            case 3:
                play_previous(&playlist);
                break;
            case 4:
                printf("Enter song index to switch to: ");
                scanf("%d", &index);
                switch_to_song(&playlist, index - 1); // Adjusting index for zero-based array
                break;
            case 5:
                printf("Enter genre to filter by: ");
                scanf(" %[^\n]%*c", genre);
                display_songs_by_genre(&playlist, genre);
                break;
            case 6:
                display_current_song(&playlist);
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}